import pyttsx3  # pip install pyttsx3
import datetime
import speech_recognition as sr  # pip install SpeechRecognition
import wikipedia  # pip install wikipedia
from googlesearch import search  # pip install google
import webbrowser
import os
import ctypes
import random
from bs4 import BeautifulSoup as soup
from urllib.request import urlopen

engine = pyttsx3.init()
i = 0
name = ""


def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def name0():
    speak("what is my new name Sir!")
    speak("PLease type my new name Sir!")
    query3 = input("Enter my new name sir: ")
    speak("I am happy to have that name Sir")
    rew = open("name0.txt", 'w')
    rew.write(query3.lower())
    name0_read()
    rew.close()


def name1():
    speak("Haaw Sir!")
    speak("You are changing my name, Anyways no problem with me")
    speak("what is my new name Sir!")
    speak("PLease type my new name Sir!")
    query3 = input("Enter my new name sir: ")
    speak("I am happy to have that name Sir")
    remm = open("name1.txt", 'w')
    remm.write(query3.lower())
    name1_read()
    remm.close()


def name1_read():
    req = open("name1.txt", 'r')
    global name
    name = req.read()


def name0_read():
    res = open("name0.txt", 'r')
    global name
    name = res.read()


def jarvis_to_sunday():
    speak("Why u want to call her sir? Am I not working properly! Anyways i Will call her")
    sound = engine.getProperty('voices')
    engine.setProperty('voice', sound[1].id)
    speak("Hello Sir! I am happy that you called me")
    speak("You made my day sir")
    name1_read()


def sunday_to_jarvis():
    speak("Why u want to call him sir? Am I not working properly! Anyways i Will call him")
    sound = engine.getProperty('voices')
    engine.setProperty('voice', sound[0].id)
    name0_read()
    speak("whats up sir!" + name + "is happy to serve you")


def time():
    time = "time right now is"
    time = time + datetime.datetime.now().strftime("%I:%M %p")
    speak(time)


def today_date():
    date = "Today's date is "
    year = int(datetime.datetime.now().year)
    month = int(datetime.datetime.now().month)
    day = int(datetime.datetime.now().day)
    date = date + str(day) + " " + str(month) + " " + str(year)
    speak(date)


def day_name():
    day = "Today is"
    day = day + datetime.datetime.now().strftime("%A")
    speak(day)


def master_animesh():
    speak("My master is Aniemesh")
    speak("HE is awesome")
    speak("I think he is a Programmer")


def wiki_google(query):
    if 'wikipedia' in query or 'wiki' in query:
        speak("I'm tryin' sir")
        query0 = query.replace("wikipedia", "")
        print(query0)
        speak("a second please")
        result = wikipedia.summary(query0, sentences=4)
        print(result)
        r1 = sr.Recognizer()
        with sr.Microphone() as source1:
            speak("Should i read the results?")
            speak("Yes or No I'm waiting")
            print("Listening...")
            r1.pause_threshold = 0.5
            audio1 = r1.listen(source1)

        try:
            print("Recognising...")
            query1 = r1.recognize_google(audio1)
            query1 = query1.lower()
            print(query1)
            if 'yes' in query1 or 'go' in query1:
                speak(result)
            elif 'no' in query1 or 'leave' in query1:
                speak("Cool Sir!")
                speak("No problem With me")
        except Exception as e:
            speak("Sorry sir! I didn't get it")
            speak("I am gonna skip that for now")
    elif 'google' in query or 'chrome' in query:

        speak("I'm tryin' sir")
        if 'google' in query:
            query0 = query.replace('google', "")
        else:
            query0 = query.replace('chrome', "")
        speak("should i open browser for you?")
        r5 = sr.Recognizer()
        with sr.Microphone() as source1:
            print("Listening...")
            r5.pause_threshold = 0.5
            audio1 = r5.listen(source1)

        try:
            print("Recognising...")
            query3 = r5.recognize_google(audio1)
            query3 = query3.lower()
            print(query3)
            if 'yes' in query3 or 'go' in query3 or 'why not' in query3:
                chromepath = "C:/Program Files (x86)/Google/Chrome/Application/chrome.exe %s"
                url = "https: // www.google.com / results?search_query =" + str(query3).replace(" ", "-")
                webbrowser.get(chromepath).open_new_tab(url)
                speak("Are you done Sir?")
                inp = input("done? Yes or No: ")
                while True:
                    if inp.lower() == 'yes':
                        break
                    elif inp.lower() == "no":
                        speak("Then i think I am leaving sir")
                        speak("See you soon! Bye!")
                    else:
                        speak("Enter a valid Input")
                        print("Valid input please")
            elif 'no' in query3 or 'leave' in query3:
                speak("Ok Sir!")
                for j in search(query0, tld="co.in", num=10, stop=10, pause=2):
                    print(j)
                speak("I printed the search results")
                speak("i'm not gonna say those links for you")
        except Exception as e:
            speak("Sorry sir! I didn't get it")
            speak("I am gonna skip that for now")


    else:
        speak("Should i search from google or wikipedia?")
        r2 = sr.Recognizer()
        with sr.Microphone() as source3:
            print("Listening...")
            r2.pause_threshold = 0.5
            audio = r2.listen(source3)
        try:
            print("Recognising...")
            query2 = r2.recognize_google(audio)
            query2 = query2.lower()
            print(query2)
            if 'google' in query2:
                q = query + "google"
                wiki_google(q)
            elif 'wikipedia' in query2:
                q = query + "wikipedia"
                wiki_google(q)
            else:
                speak("Okay sir! waiting for next instructions")
        except Exception as e:
            speak("Sorry")
            speak("I m not getting    What You are saying")
            speak("i'm gonna skip that")


def wish_me():
    sound = engine.getProperty('voices')
    engine.setProperty('voice', sound[i].id)

    if i == 0:
        name0_read()
        hour = datetime.datetime.now().hour
        if 4 <= hour <= 11:
            speak("Good Morning Sir!")
        elif 11 < hour <= 15:
            speak("Good afternoon sir!")
        elif 15 < hour < 19:
            speak("Good Evening Sir")
        else:
            speak("Hii whats up ")
        speak(name + "is always ready to help you")

    elif i == 1:
        name1_read()
        speak("Welcome back sir!")
        speak(" It's  " + name)
    speak("How was your Day")
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 0.5
        audio = r.listen(source)

    try:
        print("Recognising...")
        query = r.recognize_google(audio)
        query = query.lower()
        print(query)
        if 'good' in query or 'awesome' in query or 'amazing' in query or 'happy' in query or 'lovely' in query:
            speak("Good to hear that Sir!")
            speak("I am happy For you")
        else:
            speak("I hope")
            speak("remaining day will be cool!")

    except Exception as e:
        query = 00
        print(e)
        return "None"


def shutdown_restart(query):
    if 'logout' in query:
        speak("Logging out of system")
        os.system("shutdown -l")
    elif 'restart' in query:
        speak("restarting the system")
        os.system("shutdown /r /t 1")
    elif 'shutdown' in query:
        speak("shutdown the system")
        os.system("shutdown /s /t 1")
    else:
        speak("Locking the windows")
        ctypes.windll.user32.LockWorkStation()


def new_today():
    try:
        news_url = "https://news.google.com/news/rss"
        Client = urlopen(news_url)
        xml_page = Client.read()
        Client.close()
        soup_page = soup(xml_page, "xml")
        news_list = soup_page.findAll("item")
        for news in news_list[:15]:
            speak(news.title.text.encode('utf-8') + "!")
            print(news.title.text.encode("utf-8"))
    except Exception as e:
        print(e)


def play_songs():
    path_songs = os.path.exists('C:/Users/asus/Desktop/Music/')
    print(path_songs)
    if path_songs:
        songs_dir = 'C:/Users/asus/Desktop/Music/'
        songs = os.listdir(songs_dir)
        if len(songs) != 0:
            os.startfile(os.path.join(songs_dir, songs[0]))
            while True:
                speak("Tell me when you are free")
                inp = input("Are you done sir?(yes or no) ")
                if inp.lower() == 'yes':
                    break

        else:
            speak('Sir!')
            speak('How can I play if no songs are there')
            speak("Add some songs there")

    else:
        directory = "Music"
        parent_directory = "C:/Users/asus/Desktop/"
        path = os.path.join(parent_directory, directory)
        try:
            os.mkdir(path)
            speak("I made the music Directory")
            speak("Now go and add some songs there")
        except OSError as error:
            print(error)
            speak("Unable to make directory")
            speak("So basically Cant play songs right now")


def remember_jarvis():
    query3 = ""
    speak("what should i remember sir")
    while True:
        r = sr.Recognizer()
        with sr.Microphone() as source:
            print("Listening...")
            r.pause_threshold = 0.5
            audio = r.listen(source)

        try:
            print("Recognising...")
            query2 = r.recognize_google(audio)
            print(query2)
        except Exception as e:
            query2 = 00
            print(e)
        if query2 != 00:
            query3 = query2
            break
        else:
            speak("Can you try again sir")
    query3 = str(query3) + ".txt"
    rem = open(query3, 'a')
    speak("What should i Write sir")
    speak("Tell me when u are done")
    query5 = 00
    while True:
        r = sr.Recognizer()
        with sr.Microphone() as source:
            print("Listening...")
            r.pause_threshold = 1
            audio = r.listen(source)

        try:
            print("Recognising...")
            query5 = r.recognize_google(audio)
            print(query5)
            if 'done' in query5 and name in query5:
                break
            rem.write(query5 + "\n")
        except Exception as e:
            query5 = 00
            speak("Can you say that again please")
            print(e)
        query5 = str(query5).lower()
        speak("I saved the file Sir")
    rem.close()


def open_remember():
    speak("What should i show u sir")
    while True:
        r = sr.Recognizer()
        with sr.Microphone() as source:
            print("Listening...")
            r.pause_threshold = 0.5
            audio = r.listen(source)

        try:
            print("Recognising...")
            query9 = r.recognize_google(audio)
            print(query9)
        except Exception as e:
            query9 = 00
            print(e)
        if query9 != 00:
            break
    try:
        query9 = query9.trim() + ".txt"
        rem = open(query9, 'r')
        speak("remembered file is printed! you can check")
        print(rem.read())
        speak("Should I read the file?")
        r = sr.Recognizer()
        with sr.Microphone() as source:
            print("Listening...")
            r.pause_threshold = 0.5
            audio = r.listen(source)

        try:
            print("Recognising...")
            query = r.recognize_google(audio)
            print(query)
            if 'yes' in query or 'why not' in query or 'go' in query:
                speak(rem.read())
            else:
                speak("You can check the file.")
        except Exception as e:
            query = 00
            print(e)
            speak("I'm not getting what you said")

    except Exception as e:
        print(e)


def takeCommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        speak("I am Listening Sir")
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Recognising...")
        query = r.recognize_google(audio)
        speak("Cool!")
        print(query.lower())
    except Exception as e:
        query = 00
        print(e)
        return "None"
    query = str(query).lower()
    return query


if __name__ == "__main__":
    name = ""
    i = random.choice([0, 1])

    wish_me()
    while True:
        query = takeCommand().lower()
        # for time - "current time please"
        if ' time' in query:
            time()
        # for date - "today's date"
        elif ' date' in query:
            today_date()
        # for day
        elif ' day' in query:
            day_name()
        # for general greetings - use "Hello" with assistant's name
        elif ('hello' in query or 'hi' in query or "what's up" in query) and name in query:
            speak("Hello Sir")
            speak("i'm fine sir what I must do for you")
        # About assistant - "About Yourself"
        elif ' about' in query or 'who are u' in query or '':
            if ' yourself' in query:
                speak("that's a secret")
                speak("Can't tell u that")
            # about your master
            elif 'master' in query or 'an':
                master_animesh()
        # for wikipedia or google search - use "What is" or "Search"
        elif 'search' in query or 'what is' in query:
            wiki_google(query)
        # to shutdown, restart, logout or lock screen - use desired operation with screen or windows
        elif (
                'shutdown' in query or 'restart' in query or 'logout' in query or 'lockscreen' in query or 'lock screen' in query or 'lock' in query) and (
                'system' in query or 'windows' in query or 'screen' in query):
            shutdown_restart(query)
        # for playing songs - "play songs" or "play music"
        elif 'play' in query and ('songs' in query or 'song' in query or 'music' in query or 'musics' in query):
            play_songs()
        # try saying "Fu*k You" ;)
        elif 'f*** you' in query:
            speak("Fuck you back")
            speak("Don't abuse sir")
        # to shutdown assistant - use "switch off" or "shutdown" with name of assistant
        elif (
                'switch off' in query or 'shutdown' in query or 'f*** of' in query or 'f*** off' in query or 'bye' in query) and name in query:
            print(name)
            speak("Thank You!")
            speak("I think i must go!")
            speak("bye Sir! See You later!")
            quit()
        elif "what's" in query and 'name' in query and ('her' in query or 'him' in query):
            if i == 0:
                rem = open('name1.txt', 'r')
                speak("She is! " + rem.read())
                print(rem.read())
            else:
                rem = open('name0.txt', 'r')
                speak("he is! " + rem.read())
                print(rem.read())
        # Asking assistant to remember something - use "Remember" with name of assistant
        elif 'remember' in query:
            if name in query and 'folder' not in query:
                remember_jarvis()
            # to check remembered folder - use "remember folder"
            elif 'folder' in query:
                open_remember()
            else:
                speak("Sorry Sir!")
                speak("Either i got u wrong or i Can't do that")
        # to change name of assistant - use "change" and current name of assistant
        elif name in query and 'change' in query:
            if i == 0:
                name0()
            elif i == 1:
                name1()
        # Asking current name of assistant - "Your name please"
        elif 'your' in query and 'name' in query:
            if i == 0:
                rem = open('name0.txt', 'r')
                speak("I am " + rem.read())
            else:
                rem = open('name1.txt', 'r')
                speak("I am " + rem.read())
        # to call other assistant - use "call" and other assistant's name
        elif 'call' in query or 'cal' in query:
            rem = open('name0.txt', 'r')
            rem1 = open('name1.txt', 'r')

            if rem1.read() in query:
                if i == 0:
                    jarvis_to_sunday()
                if i == 1:
                    speak("I am " + rem1.read())
            elif rem.read() in query:
                if i == 1:
                    sunday_to_jarvis()
                else:
                    speak("I am " + rem.read() + " speaking Sir")
            else:
                speak("Who is this person?")
                speak("Are you hiring some new Assistant? Sir")
        # To make assistant wait for you - use "wait" with assistant's name
        elif 'wait' in query and name in query:
            speak("I will be ready")
            speak("When you r ready")
            speak("Just type yes to call me")
            s = input("Are you Ready:(yes or no) ")
            s = s.lower()
            if s == "no":
                speak("Cool! Sir")
                speak("No problem Sir")
                speak("I am Waiting")
                speak("type yes to call me")
                s = input("Are you Ready:(yes or no) ")
                s = s.lower()
            if s == 'yes':
                speak("Welcome back sir!")
        # for today's news - "Today's news"
        elif "today's news" in query or 'news for today' in query:
            new_today()
        elif query != 00:
            speak("Sorry Sir!")
            speak("Either i got u wrong or i Can't do that")
