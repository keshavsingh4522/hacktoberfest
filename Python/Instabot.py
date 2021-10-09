from selenium import webdriver
from time import sleep
from getpass import getpass
import os
username = input('Enter your username:- ')
pw = getpass('Enter your password:- ')

class InstaBot:
    def __init__(self, username, pw):
        
        self.driver = webdriver.Chrome()
        self.username = username
        
        
        self.driver.get("https://instagram.com")
        sleep(2)
        
        self.driver.find_element_by_xpath("//input[@name=\"username\"]")\
            .send_keys(username)
        self.driver.find_element_by_xpath("//input[@name=\"password\"]")\
            .send_keys(pw)
        self.driver.find_element_by_xpath('//button[@type="submit"]')\
            .click()
        sleep(4)
        self.driver.find_element_by_xpath("//button[contains(text(), 'Not Now')]")\
            .click()
        sleep(2)

    def get_unfollowers(self):
        self.driver.find_element_by_xpath("//a[contains(@href,'/{}')]".format(self.username))\
            .click()
        sleep(4)
        self.driver.find_element_by_xpath("//a[contains(@href,'/following')]")\
            .click()
        following = self._get_names()
        self.driver.find_element_by_xpath("//a[contains(@href,'/followers')]")\
            .click()
        followers = self._get_names()
        not_following_back = [user for user in following if user not in followers]

        #print(not_following_back)
        fw = open('instagram.txt','w')
        fw.write('\t\t\t\t\t\t NOT FOLLOWING BACK \n')
        fw.write('\t\t\t\t\t\t====================\n')
        for nam in not_following_back:
            fw.write("%s\n" % nam)
        fw.close()
        os.startfile('E:\SONU\CodingStuff\sonu\instagram.txt')  
        
        self.driver.find_element_by_xpath("//*[@id='react-root']/section/main/div/header/section/div[1]/div/button")\
            .click()
        self.driver.find_element_by_xpath("/html/body/div[4]/div/div/div/button[9]")\
            .click()
        
    
    def _get_names(self):
             
        
        sleep(2)
        scroll_box = self.driver.find_element_by_xpath("/html/body/div[4]/div/div[2]")
        last_ht, ht = 0, 1
        while last_ht != ht:
            last_ht = ht
            sleep(2)
            ht = self.driver.execute_script("""
                arguments[0].scrollTo(0, arguments[0].scrollHeight); 
                return arguments[0].scrollHeight;
                """, scroll_box)
        links = scroll_box.find_elements_by_tag_name('a')
        names = [name.text for name in links if name.text != '']
        # close button
        self.driver.find_element_by_xpath("/html/body/div[4]/div/div[1]/div/div[2]/button")\
            .click()
        
        return names
        exit()
        
        
        


my_bot = InstaBot(username, pw)
my_bot.get_unfollowers()
