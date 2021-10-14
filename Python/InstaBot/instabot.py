from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.keys import Keys
from time import sleep
import random
import datetime

'''======================
 Hashtag List liking bot using Selenium Chromedriver and Python.
 Replace your Instagram Username and Password.
 Enter the hashtag in the empty list.
 Enter the no of post to like. 
 If you like to run this bot with headless browser change "toRunwith" to True.
 Your all up and ready to roll!
							
====================== '''

#=============================================

''' Edit Below '''
#Login Credentials
username = ("")
password = ("")

#Hashtags to like
hashtags = [ ]

#No of post to like
no_of_post_to_like = 3

#Minutes to Sleep
min_to_sleep = 0.5
#sleeps for 30sec

#run with headless
toRunwith = False

#chromedriver path
path = ("C:\\chromedriver\\chromedriver.exe") 

#=============================================

class InstagramBot:
	def __init__(self,username,password):
		
		time = datetime.datetime.now()
		#Day Month Year | Hour Min Sec
		stamp = (time.strftime("%d ""%b ""%Y" " | " "%I:""%M:""%S"))        

		if toRunwith == True:
			#Run with Headless
			print("Running with Headless")
			options = webdriver.ChromeOptions()
			options.add_argument('--headless')
			self.driver = webdriver.Chrome(executable_path=path, options=options)
		else :
			#Run without Headless
			print("Running without Headless")
			self.driver = webdriver.Chrome(executable_path=path)
		
		#Login Code
		self.driver.get("https://www.instagram.com/accounts/login/")
		sleep(4)
		self.driver.find_element_by_xpath("//input[@name=\"username\"]")\
			.send_keys(username)
		self.driver.find_element_by_xpath("//input[@name=\"password\"]")\
			.send_keys(password)
		self.driver.find_element_by_xpath("//button[@type=\"submit\"]")\
			.click()
		print("Login Successfull")
		sleep(5)

		totalHashtag = 0
		#Looping through hashtags list
		for hashtag in hashtags:
			totalHashtag += 1
			current_hashtag = ("Processing #" + hashtag)
			post_str = ("No of Post to like - " + str(no_of_post_to_like))

			print("==================================")
			print(current_hashtag)
			print(post_str)
			print("==================================")

			self.driver.get('https://www.instagram.com/explore/tags/' + hashtag)
			self.driver.find_element_by_class_name('v1Nh3').click()
			i = 1
			#Liking posts
			while i<= no_of_post_to_like:
				sleep(random.randint(4,10))
				self.driver.find_element_by_class_name('fr66n').click()
				self.driver.find_element_by_class_name('coreSpriteRightPaginationArrow').click()
				sleep(3)
				i += 1
				time = datetime.datetime.now()
				stamp = (time.strftime("%I"":""%M"":""%S"))
				currentPost = i - 1
				currentPost_str = str(currentPost)
				print(("Liked post no : " + currentPost_str + " | " + stamp ))

			#Scroll function
			sleep(2)
			self.driver.get('https://www.instagram.com/explore/tags/' + hashtag)
			self.driver.execute_script("window.scrollTo(0,500)")
			sleep(1)
			self.driver.execute_script("window.scrollTo(0,1000)")
			sleep(1)
			self.driver.execute_script("window.scrollTo(0,2050)")
			completed = ("Successfully completed #" + hashtag)
			print("==================================")
			print(completed)
			print("==================================")
			sleep(min_to_sleep*60)
		print("Objective Completed")



hashtag_bot = InstagramBot(username,password)
