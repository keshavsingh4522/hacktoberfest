# importing time module
import time
#importing webbrowser module
import webbrowser

# getting current time from time module (Only Hour and minutes)
Current_time = time.strftime("%I:%M:%S")  

#Setting the opening time
set_time = input("Enter the opening_time(HH:MM:SS): ")
opening_time = time.strftime(set_time)

#Url you want to open
url = input("Enter the url: ")

#Looping until the opening time and current time matches
while (Current_time != opening_time):
	print("Current Time: " + Current_time)
	Current_time = time.strftime("%I:%M:%S")
	time.sleep(1)

#Opens when time matches
if Current_time == opening_time:
	webbrowser.open(url)
	print("Its time")
