from selenium import webdriver
import sys

# function to convert a list into string
def convert(s): 
    str1 = "" 
    return(str1.join(s)) 

# Assign the arguments passed to a variable search_string
search_string = sys.argv[1:] 

# The argument passed to the program is accepted
# as list, it is needed to convert that into string
search_string = convert(search_string)

# This is done to structure the string 
# into search url.(This can be ignored)
search_string = search_string.replace(' ', '+') 


# Assigning the browser variable with chromedriver of Chrome.
# Any other browser and its respective webdriver 
# like geckodriver for Mozilla Firefox can be used
browser = webdriver.Chrome('chromedriver')


for i in range(1):
    matched_elements = browser.get("https://www.google.com/search?q=" + 
                                   search_string + "&start=" + str(i))
