# -*- coding: utf-8 -*-

import datetime

import requests
from bs4 import BeautifulSoup


def connect_to_api(api, username):
    """Connection Handler"""
    TARGET_API = f"https://www.instadp.com/fullsize/{username}"
    BACKUP_API = f"https://www.instagram.com/{username}/?__a=1"

    headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) '
                             'Chrome/41.0.2228.0 Safari/537.36'}

    if api == "target":
        r = requests.get(TARGET_API, headers=headers)
        html = r.text
        soup = BeautifulSoup(html, 'lxml')
        try:
            profile_pic = soup.find("img", class_="picture").attrs["src"]
        except AttributeError:
            return "User not found D:"

        if profile_pic != "":
            return profile_pic
        else:
            return None

    elif api == "backup":
        r = requests.get(BACKUP_API, headers=headers)
        resp = r.json()
        if len(resp) == 0:
            return "User not found D:"
        print("Connected!\n")
        profile_pic = resp["graphql"]["user"]["profile_pic_url_hd"]
        return profile_pic


def main_func():
    """Image scraper for High-Definition Instagram Profile Pics"""
    username = str(input("Enter an Instagram Username : "))
    start = datetime.datetime.now()
    print("\nConnecting...\n")
    _profilepic = connect_to_api("target", username)
    if _profilepic is not None:
        print(_profilepic)
    else:
        print("Target API Failed!...Trying the Backup Method\n")
        _profilepic = connect_to_api("backup", username)
        print(_profilepic)

    end = datetime.datetime.now()
    total_time = (end - start).total_seconds()
    print(f"\nDone!")

    input(f"Total time taken : {total_time} seconds")


if __name__ == '__main__':
    main_func()
