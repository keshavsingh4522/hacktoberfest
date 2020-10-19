from pytube import YouTube, exceptions
import logging

# Enable Logger
logging.basicConfig(
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s', level=logging.WARN)
logger = logging.getLogger(__name__)


def download_video(link: str) -> str:
    '''Try to download video in Highest Res. and return saved path'''
    try:
        yt = YouTube(link)  # initializing YouTube object
        print(f'Title: {yt.title}')
        print(f'Channel: {yt.author}')
        print(f'Duration: {yt.length}')
        path = yt.streams.get_highest_resolution().download('downloads')
        return path

    except exceptions.RegexMatchError:
        logger.error(msg='Not a Valid YouTube URL')
        return None

    except exceptions.LiveStreamError:
        logger.error(msg='Live Streams Cannot be Downloaded')
        return None

    except exceptions.VideoUnavailable:
        logger.error(msg='Video is Unavailable')
        return None

    except exceptions.HTMLParseError:
        logger.error(msg='Given URl could not be Parsed')
        return None


if __name__ == '__main__':
    link = input('Enter a valid YouTube Link : ')
    save_path = download_video(link)
    if(save_path):
        print(f'Video Downloaded at {save_path}')
    else:
        print('Some Error occured, check Log for more details')
