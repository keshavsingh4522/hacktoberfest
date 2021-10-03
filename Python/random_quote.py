import json
import requests

"""
    Random Anime Quote
"""

if __name__ == "__main__":

    # get data from api
    data = requests.get(
        "https://api.animemoe.us/quotes/random/v2/",
        headers={
            "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.61 Safari/537.36"
        },
    )

    if data.status_code == 200:
        data = json.loads(data.text)
        print(f"{data['quote']}\n— {data['character']}, {data['anime']}")
    else:
        print("try again")
