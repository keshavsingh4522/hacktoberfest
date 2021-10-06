import re
import os
import json
import math
import logging
import requests
import collections

from time import sleep
from lxml import html, etree
from bs4 import BeautifulSoup
from unidecode import unidecode
from multiprocessing import Pool

class ArtistCliche:
    BASE_URL = 'https://www.letras.mus.br'

    def __init__(self, name, verbose=True, n_pools=1):
        self.raw_artist_name = name.title()
        self.artist_name = self._treat_artist_name(name)
        self.n_pools = n_pools
        self.verbose = verbose
        self.max_songs = 1000000
        self.total_songs = 0

        if verbose:
            logging.basicConfig(level=logging.INFO)

    def set_n_pools(n_pools):
        self.n_pools = n_pools
    
    def set_max_songs(max_songs):
        self.max_songs = max_songs

    def _treat_artist_name(self, name):
        name = name.lower()
        name = unidecode(name)
        name = name.replace(' ', '-')
        return name

    def _get_lyrics_from_tag(self, songs_tags):
        all_lyrics = []

        num_songs = min(self.max_songs, len(songs_tags))
        if self.verbose:
            logging.info(f'Getting {num_songs} out of {len(songs_tags)}')

        for amount, url in enumerate(songs_tags, 1):
            if amount >= self.max_songs:
                break
            
            if self.verbose:
                logging.info(f'[{amount}/{num_songs}] {url}')
            
            response = requests.get(url)
            
            tree = html.fromstring(response.content)
            lyrics_div = tree.xpath('//div[@class="cnt-letra p402_premium"]')
            
            try:
                lyrics = self._parse_lyrics(lyrics_div)
                all_lyrics.append(lyrics)
            except:
                logging.warning('Could not get lyrics')
        
        return all_lyrics

    def _get_lyrics_from_tag_pararell(self, songs_tags):
        num_songs = min(self.max_songs, len(songs_tags))
        
        if self.verbose:
            logging.info(f'Getting {num_songs} out of {len(songs_tags)}')
        
        pool = Pool(self.n_pools)

        args = []
        num_songs_per_pool = math.ceil(num_songs / self.n_pools)
        
        for start in range(0, num_songs, num_songs_per_pool):
            end = min(start + num_songs_per_pool, self.max_songs)
            pool_num = start//num_songs_per_pool+1
            args.append((pool_num, songs_tags[start:end]))

        lyrics_from_processes = pool.starmap(self._handle_process, args)
        
        all_lyrics = []
        for lyrics_list in lyrics_from_processes:
            all_lyrics.extend(lyrics_list)
        
        return all_lyrics

    def _handle_process(self, pool_num, songs_tags):
        num_songs = len(songs_tags)
        local_all_lyrics = []

        for amount, url in enumerate(songs_tags, 1):            
            if self.verbose:
                logging.info(f'{pool_num}: [{amount}/{num_songs}] {url}')
            
            sleep(0.5)
            response = requests.get(url)
            
            tree = html.fromstring(response.content)
            lyrics_div = tree.xpath('//div[@class="cnt-letra p402_premium"]')
            
            try:
                lyrics = self._parse_lyrics(lyrics_div)
                local_all_lyrics.append(lyrics)
            except:
                logging.warning('Could not get lyrics')
        
        return local_all_lyrics

    def _parse_lyrics(self, lyrics_div):
        lyrics = ''
        stanzas = lyrics_div[0].xpath('.//p')
        
        for st in stanzas:
            lyrics += etree.tostring(st).decode("utf-8") + ' '
        
        lyrics = lyrics.replace('<br>', ' ').replace('<br/>', ' ').replace('<p>', ' ').replace('</p>', ' ')
        lyrics = lyrics.lower()
        lyrics = unidecode(lyrics)
        return lyrics

    def _count_words(self, all_lyrics):
        count = {}
        
        for lyrics in all_lyrics:
            all_words = lyrics.strip().split()
            # all_words = re.findall(r'\w+', lyrics)
            
            for word in all_words:
                if word not in count:
                    count[word] = 1
                else:
                    count[word] += 1

        count_sorted = self._sort_dict(count)
        
        return count_sorted

    def _sort_dict(self, x):
        return {k: v for k, v in sorted(x.items(), key=lambda item: item[1], reverse=True)}

    def _get_song_urls(self, songs_tags):
        songs = []
        
        for song in songs_tags:
            song_url = self.BASE_URL + song['href']
            songs.append(song_url)
        
        return songs
    
    def get_words_count(self, max_songs=10000000, n_pools=1):
        artist_url = f'{self.BASE_URL}/{self.artist_name}'
        
        if self.verbose:
            logging.info(f"Getting {self.raw_artist_name}'s songs from {artist_url}")
        
        response = requests.get(artist_url)
        
        if response.status_code != 200:
            logging.error(f'Something wrong: {response.status_code} - {response.reason}')
            return {}

        soup = BeautifulSoup(response.text, 'lxml')
        songs_tags = soup.find_all('a', {'class': 'song-name'}, href=True)

        self.max_songs = min(max_songs, len(songs_tags))
        self.total_songs = len(songs_tags)
        song_urls = self._get_song_urls(songs_tags)

        self.n_pools = n_pools
        all_lyrics = self._get_lyrics_from_tag_pararell(song_urls)
        
        self.count = self._count_words(all_lyrics)

        return self.count

class Hollywood:
    def __init__(self, filename='word_count.json'):
        if os.path.exists(filename):
            print(f'Reading artists from {filename}')
            with open(filename, 'r') as f:
                self.artists = json.loads(f.read())
        else:
            self.artists = {}

    def find_artist(self, name):
        if name in self.artists:
            return self.artists[name]
        else:
            return None

    def must_add_artist(self, artist):
        return (artist is None)

    def must_update_artist(self, artist, max_songs):
        if (artist['num_songs_gathered'] != artist['num_songs']) and (artist['num_songs_gathered'] < max_songs):
            return True

        return False

    def add_artist(self, name, get_words_count=True, max_songs=1000000, n_pools=1):
        new_artist = ArtistCliche(name)
        artist_in_list = self.find_artist(name)

        if not get_words_count:
            if self.find_artist(name) is None:
                print('Adding artist')
                base_row = {}
                base_row['name'] = new_artist.raw_artist_name
                base_row['name_clean'] = new_artist.artist_name
                base_row['num_songs'] = None
                base_row['songs_gathered'] = 0
                row = {new_artist.artist_name: base_row}
                self.artists.update(row)
            
            return

        if self.must_add_artist(artist_in_list) or self.must_update_artist(artist_in_list, max_songs):
            print('Getting data and adding artist')
            new_artist.get_words_count(max_songs=max_songs, n_pools=n_pools)

            base_row = {}
            base_row['name'] = new_artist.raw_artist_name
            base_row['name_clean'] = new_artist.artist_name
            base_row['num_songs'] = new_artist.total_songs
            base_row['num_songs_gathered'] = new_artist.max_songs
            base_row['words'] = new_artist.count
            row = {new_artist.artist_name: base_row}
            self.artists.update(row)

    def to_json(self, filename='word_count.json'):
        with open(filename, 'w') as f:
            json.dump(self.artists, f, indent=4)
        
        # for idx, artist in self.artists.items():
            

        #     if os.path.exists('word_count.json'):

                
        #         if self.artist_name not in word_count_json:
        #             print('Not found, adding to json')
        #             word_count_json.update(row)
                
        #         if len(count) > len(word_count_json[self.artist_name]['words']):
        #             print('New words!!')
        #             word_count_json.update(row)
        #     else:
        #         word_count_json = {}
        #         word_count_json[self.artist_name] = row

if __name__ == '__main__':
    artists = Hollywood(filename='teste.json')
    artists.add_artist('billie eilish', max_songs=1, n_pools=2)
    artists.to_json(filename='teste.json')