import json
import requests
import time
from playsound import playsound

SELLING_PRICE  =  34900
print ("Selling price is", SELLING_PRICE)
print ("Reading...")

def price_check():
    url = "https://min-api.cryptocompare.com/data/price"

    querystring = {"fsym":"BTC","tsyms":"USD"}

    response = requests.request("GET", url, params=querystring)
    response = json.loads(response.text)
    current_price = response['USD']
    return current_price

while True:
    market_price = price_check()
    print ("...")
    print ("Market price is ", market_price)
      
   
    time.sleep(4)
    if market_price < SELLING_PRICE:
        print ("Holy Shit. Sell it ALL !!")
        playsound('alert.wav')