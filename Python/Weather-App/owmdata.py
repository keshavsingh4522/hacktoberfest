import requests, json
from datetime import *
from pprint import pprint

def weather_info(city):
    url = 'https://api.openweathermap.org/data/2.5/weather'
    API_KEY='' #Add Your OpenWeatherMap API in ""

    if (API_KEY == '' or API_KEY.isspace()):
            print('Please provide API Key')
            exit
    params = {
        'appid' : API_KEY,
        'q' : city,
        'units' : 'metric'
    }

    response = requests.get(url, params)
    request = response.json()

    icon = request['weather'][0]['icon']

    main = request['main']
    temp = 'Temperature : ' + str(main['temp']) + ' °C'
    humidity = 'Humidity : ' + str(main['humidity']) + '%'
    wind = 'Wind Speed : '+ str(round(float(request['wind']['speed'])*5/18,2)) + ' km/h'
    clouds = 'Cloud details : ' + str(request['weather'][0]['description']).capitalize()
    sunrise = 'Sunrise Time : ' + str(datetime.fromtimestamp(
            int(request['sys']['sunrise'])
            ).strftime('%H:%M')) + ' IST'
    sunset = 'Sunset Time : ' + str(datetime.fromtimestamp(
            int(request['sys']['sunset'])
            ).strftime('%H:%M')) + ' IST'

    date = datetime.fromtimestamp(request['dt']).strftime('%Y/%m/%d')

    return [[temp, humidity, wind, clouds, sunrise, sunset],[icon, date]]
