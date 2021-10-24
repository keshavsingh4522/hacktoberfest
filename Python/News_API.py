
# ************************* News API (Application Programming Interface) ***************************

# Required Libraries
from win32com.client import Dispatch
from datetime import datetime
import json
import requests

def loop(msg):
    for i in msg:
        print(i, end=", ")

# This engine will speak the news fetch by rest API
def speak(msg):
    speak = Dispatch("SAPI.SpVoice")
    speak.Speak(msg)

# This will record our movements in program
def login(msg):
    global name
    with open("record.txt", "a") as f:
        f.write(f"{name.capitalize()} has {msg} on {datetime.now()}\n")

if __name__ == '__main__':
    print("\nWelcome to News API made by Sachin Dabhade\n")
    name = input("Enter your name: ")
    print("\nHello " + name.capitalize() + "! Best of Luck!")
    print("\nThe News API is starting...!\n Let's Enjoy the programme...!\n\n")
    login("started News API")

    # Country names and category is fetching
    countrys = {'Argentina': 'ar', 'Australia': 'au', 'Austria': 'at', 'Belgium': 'be', 'Brazil': 'br',
                'Bulgaria': 'bg', 'Canada': 'ca', 'China': 'cn', 'Colombia': 'co',
                'Cuba': 'cu', 'Czech Republic': 'cz', 'Egypt': 'eg', 'France': 'fr', 'Germany': 'de', 'Greece': 'gr',
                'Hong Kong': 'hk', 'Hungary': 'hu', 'India': 'in',
                'Indonesia': 'id', 'Ireland': 'ie', 'Israel': 'il', 'Italy': 'it', 'Japan': 'jp', 'Latvia': 'lv',
                'Lithuania': 'it', 'Malaysia': 'my', 'Mexico': 'mx',
                'Morocco': 'ma', 'Netherlands': 'nl', 'New Zealand': 'nz', 'Nigeria': 'ng', 'Norway': 'no',
                'Philippines': 'ph', 'Poland': 'pl', 'Portugal': 'pt',
                'Romania': 'ro', 'Russia': 'ru', 'Saudi Arabia': 'sa', 'Serbia': 'rs', 'Singapore': 'sg',
                'Slovakia': 'sk', 'Slovenia': 'si', 'South Africa': 'za',
                'South Korea': 'kr', 'Sweden': 'se', 'Switzerland': 'ch', 'Taiwan': 'tw', 'Thailand': 'th',
                'Turkey': 'tr', 'UAE': 'ae', 'Ukraine': 'ua',
                'United Kingdom': 'gb', 'United States': 'us', 'Venuzuela': 've'}
    loop(countrys)
    country = input("\n\nEnter the Country (EX. India):")
    country1 = countrys.get(country.capitalize())
    
    # Enter the category that you like to here
    categories = ['business', 'entertainment', 'health', 'science', 'sports', 'technology']
    loop(categories)
    category = input("\n\nEnter the category (EX. Science):")
    
    # Checking the input category is valid or not
    if category not in categories:
        print("Invalid input....! Please try again....!")
        speak("Invalid input....! Please try again....!")
        exit()
    
    # url from which the news will fetch
    url = (
        f'https://newsapi.org/v2/top-headlines?country={country1.lower()}&category={category.lower()}&apiKey=2114b271bda54165b23a311b1d1e3c49')
    response = requests.get(url).text
    news = json.loads(response)
    articles = news["articles"]

    # If there is no news on this topic, then it will exit the program
    if news["totalResults"] == 0:
        speak("Sorry, there is no news on this topic...!")
        exit()
    
    # This is the news barrier to restrict number of news speak in one time
    Int = int(input("\nHow many news you want to listen (Ex. 1,2,3...):"))
    variable = 1
    
    for article in articles:
        
        print(variable)
        print(article["title"])
        
        speak(article["title"]) # Will speak the news title
        speak("The news description is ....!")
        
        print(article["description"]) 
        description = article["description"]
        speak(description) # Will speak the news description
        
        # Checking the limitation of news
        if variable == Int:
            speak("Thanks for Listening us, Meet soon...!")
            break

        speak("The next news is.....!")
        # updating the variable by 1
        variable = variable + 1

