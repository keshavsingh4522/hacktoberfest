#!/usr/bin/env python

import requests
import time

# XC API variables needed for connection
serverProtocol = 'http|https'
serverAddress = '<url.com>'
serverPort = '<serverport>'
serverUsername = '<username>'
serverPassword = '<password>'

# list of unwanted categories
unwantedCats = ['SPORTS', 'MOVIES']

urlBase = f'{serverProtocol}://{serverAddress}:{serverPort}/player_api.php?username={serverUsername}&password={serverPassword}'  # Basic account info
urlLiveCategories = f'{urlBase}&action=get_live_categories' # Get Live Categories
urlLiveStreams = f'{urlBase}&action=get_live_streams' # Get Live Stream Links

def getAccount():
    r = requests.get(urlBase)
    if (r.ok and time.time() < int(r.json()['user_info']['exp_date']) ):
        return r.json()

def getLiveCategories():
    r = requests.get(urlLiveCategories)
    if (r.ok):
        return r.json()

def getLiveStreams():
    r = requests.get(urlLiveStreams)
    if (r.ok):
        return r.json()

def buildM3u(jsonCat, jsonLive):
    output = open('playlist.m3u', 'w+')
    output.write("#EXTM3U")

    for channel in jsonLive:
        for cat in jsonCat:
            if channel['category_id'] == cat['category_id'] and cat['category_name'] not in unwantedCats:
                output.write(f'\n#EXTINF:-1 tvg-id="{ channel["epg_channel_id"] }" tvg-name="{ channel["name"] }" tvg-logo="{ str(channel["stream_icon"]) }" group-title="{ cat["category_name"] }",{ channel["name"] }\n')
                output.write(f'{ streamProtocol }://{ streamUrl }:{ streamPort }/{ serverUsername }/{ serverPassword }/{ channel["stream_id"] }')


    output.close()

accountJson = getAccount()

if accountJson is not False:
    streamUrl = accountJson['server_info']['url']
    if (accountJson['server_info']['server_protocol'] == 'https'):
        streamPort = accountJson['server_info']['https_port']
    else:
        streamPort = accountJson['server_info']['port']
    streamProtocol = accountJson['server_info']['server_protocol']

    buildM3u(getLiveCategories(), getLiveStreams() )
    print("Success!")
else:
    print("Fail!")


if __name__ == "__main__":
    # Create playlist.msu file.
    buildM3u(getLiveCategories(), getLiveStreams() )