import pyttsx3
from gtts import gTTS
import datetime
import pyowm
from pyowm.owm import OWM
from playsound import playsound
import speech_recognition as sr
import wikipedia
import os
import webbrowser
import random
import psutil
import requests, json
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions
from bs4 import BeautifulSoup
from playsound import playsound
from pygame import mixer 


engine = pyttsx3.init()



def speak(text):
    engine.say(text)
    engine.runAndWait()

def time():
    Time = datetime.datetime.now().strftime("%I:%M:%S")
    speak("the current time is")
    speak(Time)

def cpu():
    usage = str(psutil.cpu_percent())
    speak('CPU usage is at ' + usage)
    print('CPU usage is at ' + usage)


def date():
    year = int(datetime.datetime.now().year)
    month = int(datetime.datetime.now().month)
    date = int(datetime.datetime.now().day)
    speak("the current date is")
    speak(date)
    speak(month)
    speak(year)

def youtube():
    driver = webdriver.Chrome("C:\webdrivers\chromedriver.exe")
    driver.get("http://www.youtube.com")
    speak("youtube is opened")
    driver.implicitly_wait(10)
    speak("use search for searching , use back and next for navigation")
    while True:
        speak("sir, waiting for command..")
        command=takecommand().lower()
        if "search" in command:
            speak("what do you want to search")
            query=takecommand().lower()
            search = driver.find_element_by_name("search_query")
            search.send_keys(query)
            driver.find_element_by_xpath('//*[@id="search-icon-legacy"]').click()
        if "play" in command:
            flag=0
            speak("which music you want to play")
            music=takecommand().lower()
            links = driver.find_elements_by_id("video-title")
            for link in links:
                text = link.text.lower()
                if music in text:
                    link.click()
                    flag = 1
                    break
            if(flag==1):
                title=driver.title
                speak("title of music is ," + title)
            else:
                speak("music is not found plase tell sutaible name of music")
        if "back" in command:
            driver.back()
        if "next" in command:
            driver.forward()
        if "down" in command:
            driver.execute_script("window.scrollBy(0,400)", " ")

        if "close" in command:
            break
        else:
            speak("please use right command")

def personal():
    speak(
        "I am Jarvis, version 1.0, I am an AI assistent, I am developed by Vishal Vishwakarma and Aryan sharma in INDIA"
    )
    speak("Now i hope you know me")
        



def goole():
    driver = webdriver.Chrome("C:\webdrivers\chromedriver.exe")
    driver.get("http://www.google.com")
    speak("sir, what do you want to search")
    query = takecommand().lower()
    search = driver.find_element_by_name("q")
    search.send_keys(query)
    driver.implicitly_wait(20)
    btn = driver.find_element_by_xpath('//*[@id="tsf"]/div[2]/div[1]/div[3]/center/input[1]')
    btn.click()


    while True:
        speak("sir,do you want to scroll down or open any link")
        command = takecommand().lower()
        if "down" in  command:
            driver.execute_script("window.scrollBy(0,200)", " ")

        if "link" in command:
            flag=0
            speak("which link do you want to open ")
            topic=takecommand().lower()
            results = driver.find_elements_by_xpath('//div[@class="r"]/a/h3')
            for link in results:
                text = link.text.lower()
                if topic in text:
                    link.click()
                    flag=1
                    break
            if(flag==1):
                title = driver.title
                speak("title of this page is " + title)
            else:
                speak("link is not found, please try again")
        if "back" in command:
            driver.back()
        if "forward" in command:
            driver.forward()
        if "close" in command:
            break


    speak("thanks for using google")

def wishme():
    playsound('G:\jarvis\hello.mp3')
    speak("initializing System")
    speak("Welcome back sir!")
    time()
    date()
    hour = datetime.datetime.now().hour
    if hour >= 6 and hour<12:
        speak("Good Morning sir!")
    elif hour >=12 and hour<18:
        speak("Good afternoon sir!")
    elif hour >= 18 and hour<24:
        speak("Good Evening Sir!")
    else:
        speak("Good night sir")

    speak("Jarvis at your service please tell me how can i help you?")

def takecommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Recongnizing...")
        query = r.recognize_google(audio, language='en-in')
        print(query)

    except Exception as e:
        print(e)
        speak("say that again please...")

        return "None"
    return query

if __name__ == '__main__':
    wishme()
    while True:
        query = takecommand().lower()
        if 'time' in query:
            time()
        elif 'date' in query:
            date()
        elif 'wikipedia' in query:
            speak("Searching...")
            query = query.replace("wikipedia","")
            result = wikipedia.summary(query, sentences=2)
            print(result)
            speak(result)
        elif 'offline' in query:
            quit()

        elif 'hello jarvis' in query:
            speak("Hello Sir")

        elif ("tell me about yourself" in query):
            personal()
        elif ("about you" in query):
            personal()
        elif ("who are you" in query):
            personal()
        elif ("yourself" in query):
            personal()

        elif ("cpu" in query or "battery" in query
              or "cpu" in query):
            cpu()
        
        elif "will you be my gf" in query or "will you be my bf" in query:    
            speak("I'm not sure about, may be you should give me some time") 

        elif 'open youtube' in query:
            speak("youtube is opening")
            youtube()

        elif 'open google' in query:
            speak("google is opening")
            goole()

        elif 'weather' in query or "temperature" in query:
            api_key = "38584a40793317419de36000a0ae1044"
            # base_url variable to store url 
            base_url = "http://api.openweathermap.org/data/2.5/weather?"
            speak("Which city")
            # Give city name 
            city_name = takecommand().lower()
            
            # complete_url variable to store 
            # complete url address 
            complete_url = base_url + "appid=" + api_key + "&q=" + city_name 
            
            # get method of requests module 
            # return response object 
            response = requests.get(complete_url) 
            
            # json method of response object  
            # convert json format data into 
            # python format data 
            x = response.json() 
            
            # Now x contains list of nested dictionaries 
            # Check the value of "cod" key is equal to 
            # "404", means city is found otherwise, 
            # city is not found 
            if x["cod"] != "404": 
            
                # store the value of "main" 
                # key in variable y 
                y = x["main"] 
            
                # store the value corresponding 
                # to the "temp" key of y 
                current_temperature = y["temp"]-273.15 
            
                # store the value corresponding 
                # to the "pressure" key of y 
                current_pressure = y["pressure"] 
            
                # store the value corresponding 
                # to the "humidity" key of y 
                current_humidiy = y["humidity"] 
            
                # store the value of "weather" 
                # key in variable z 
                z = x["weather"] 
            
                # store the value corresponding  
                # to the "description" key at  
                # the 0th index of z 
                weather_description = z[0]["description"] 
            
                # print following values 
                speak(f" Sir the current temperature of" + city_name  + "is"
                               + str(current_temperature) + "degree celcius" 
                    "\n  with atmospheric pressure of " +
                                str(current_pressure) +
                    "\n and humidity of " +
                                str(current_humidiy) +
                    "\n with overall " +
                                str(weather_description) +"nature") 

        elif ("tell me your powers" in query or "help" in query
              or "features" in query):
            features = ''' i can help to do lot many things like..
            i can tell you the current time and date,
            i can tell you the current weather,
            i can tell you battery and cpu usage,
            i can create the reminder list,
            i can take screenshots,
            i can send email to your boss or family or your friend,
            i can shut down or logout or hibernate your system,
            i can tell you non funny jokes,
            i can open any website,
            i can tell corona virus update
            i can search the thing on wikipedia,
            i can change my voice from male to female and vice-versa
            And yes one more thing, My boss is working on this system to add more features...,
            tell me what can i do for you??
            '''
            print(features)
            speak(features)
  
        elif "i love you" in query: 
            speak("It's hard to understand")

        elif 'how are you' in query:
            stMsgs = ['Just doing my thing!', 'I am fine!', 'Nice!', 'I am nice and full of energy', "I'm fine, glad you me that"]
            speak(random.choice(stMsgs))

        elif "where is" in query: 
            query = query.replace("where is", "") 
            location = query 
            speak("User asked to Locate") 
            speak(location) 
            webbrowser.open("https://www.google.com / maps / place/" + location + "")

        elif 'who i am' in query: 
            speak("If you talk then definately your human.") 
  
        elif 'why you came to world' in query: 
            speak("Thanks to Vishal. further It's a secret") 

        elif 'reason for you' in query: 
            speak("I was created as a Minor project by Mister Vishal ")

        elif 'Thank you' in query:
            speak("I am always here to help you")

        elif 'corona virus status' in query or 'coronavirus update' in query or 'coronavirus status' in query:
            speak('which update show - worldwide ya India')
            ans = takecommand()
            if 'india' == ans or 'India' == ans:
                url = "https://www.worldometers.info/coronavirus/country/india/"
                req = requests.get(url)
                bsObj = BeautifulSoup(req.text, "html.parser")
                data = bsObj.find_all("div",class_ = "maincounter-number")

                speak("Total Cases: ")
                speak(data[0].text.strip())
                speak("Total Deaths: ")
                speak(data[1].text.strip())
                speak("Total Recovered: ")
                speak(data[2].text.strip())
            else:
                url = "https://www.worldometers.info/coronavirus/"
                req = requests.get(url)
                bsObj = BeautifulSoup(req.text, "html.parser")
                data = bsObj.find_all("div",class_ = "maincounter-number")

                speak("Total Cases: ")
                speak(data[0].text.strip())
                speak("Total Deaths: ")
                speak(data[1].text.strip())
                speak("Total Recovered: ")
                speak(data[2].text.strip())
