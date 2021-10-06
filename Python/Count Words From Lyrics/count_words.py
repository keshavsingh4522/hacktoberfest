import re
import logging
import requests
import collections
from bs4 import BeautifulSoup
from unidecode import unidecode

class ArtistCliche:
    BASE_URL = 'https://www.letras.mus.br'

    def __init__(self, name, verbose=True):
        self.raw_artist_name = name
        self.artist_name = self._treat_artist_name(name)
        self.verbose = verbose

        if verbose:
            logging.basicConfig(level=logging.INFO)

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

        for amount, song_tag in enumerate(songs_tags, 1):
            if amount >= self.max_songs:
                break
            
            if self.verbose:
                logging.info(f'[{amount}/{num_songs}] Title: {song_tag.text}')
            
            song_url = self.BASE_URL + song_tag['href']
            response = requests.get(song_url)
            
            soup = BeautifulSoup(response.text, 'lxml')
            lyrics_div = soup.find('div', {'class': 'cnt-letra p402_premium'})
            try:
                lyrics = self._parse_lyrics(lyrics_div)
                all_lyrics.append(lyrics)
            except:
                logging.warning('Could not get lyrics')
        
        return all_lyrics

    def _parse_lyrics(self, lyrics_div):
        lyrics = ''
        stanzas = lyrics_div.find_all('p')

        for st in stanzas:
            verse = str(st).replace('<br>', '\n').replace('<br/>', '\n').replace('<p>', '\n').replace('</p>', '\n')
            lyrics += verse
        
        lyrics = lyrics.lower()
        lyrics = lyrics.replace("'", '')
        lyrics = unidecode(lyrics)
        
        return lyrics

    def _count_words(self, all_lyrics):
        count = {}
        
        for lyrics in all_lyrics:
            all_words = re.findall(r'\w+', lyrics)
            
            for word in all_words:
                if word not in count:
                    count[word] = 1
                else:
                    count[word] += 1

        count_sorted = self._sort_dict(count)
        
        return count_sorted

    def _sort_dict(self, x):
        return {k: v for k, v in sorted(x.items(), key=lambda item: item[1], reverse=True)}

    def get_words_count(self, max_songs=100):

        self.max_songs = max_songs
        artist_url = f'{self.BASE_URL}/{self.artist_name}'
        
        if self.verbose:
            logging.info(f"Getting {self.raw_artist_name}'s songs from {artist_url}")
        
        response = requests.get(artist_url)
        
        if response.status_code != 200:
            logging.error(f'Something wrong: {response.status_code} - {response.reason}')
            return {}

        soup = BeautifulSoup(response.text, 'lxml')
        songs_tags = soup.find_all('a', {'class': 'song-name'}, href=True)
        
        all_lyrics = self._get_lyrics_from_tag(songs_tags)
        count = self._count_words(all_lyrics)

        return count

if __name__ == '__main__':
    artist = ArtistCliche('Os Barões da Pisadinha')
    # artist = ArtistCliche('of monsters and men')
    count = artist.get_words_count()
    
    for i, (key, value) in enumerate(count.items()):
        if i >= 50:
            break

        print(f'{key}: {value}')