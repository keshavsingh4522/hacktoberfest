
# -*- coding: utf-8 -*-
"""
Created on Wed Jul 14 19:07:43 2021

@author: Mr. Aman Saini
IIT Mandi
"""




import random
import time





##### ASCII ARTS #####
win = """
 __     ______  _    _  __          _______ _   _   _ 
 \ \   / / __ \| |  | | \ \        / /_   _| \ | | | |
  \ \_/ / |  | | |  | |  \ \  /\  / /  | | |  \| | | |
   \   /| |  | | |  | |   \ \/  \/ /   | | | . ` | | |
    | | | |__| | |__| |    \  /\  /   _| |_| |\  | |_|
    |_|  \____/ \____/      \/  \/   |_____|_| \_| (_)                                                      
"""

lose = """
 __     ______  _    _   _      ____   _____ ______   _ 
 \ \   / / __ \| |  | | | |    / __ \ / ____|  ____| | |
  \ \_/ / |  | | |  | | | |   | |  | | (___ | |__    | |
   \   /| |  | | |  | | | |   | |  | |\___ \|  __|   | |
    | | | |__| | |__| | | |___| |__| |____) | |____  |_|
    |_|  \____/ \____/  |______\____/|_____/|______| (_)                                                                                    
"""

logo = """
 __          __  _                            _          _    _                                           _ 
 \ \        / / | |                          | |        | |  | |                                         | |
  \ \  /\  / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __   | |
   \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \  |  __  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \  | |
    \  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |  | | (_| | | | | (_| | | | | | | (_| | | | | |_|
     \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/  |_|  |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_| (_)
                                                                             __/ |                          
                                                                            |___/                                             
"""




print("           ****************************************************************************************************************************")
print("********************************************************************************************************************************************************")
print("           *****************************************************************************************************************************\n\n")




name = input("What is Your Name - ")
print("Good Luck ! ", name)
time.sleep(1)
print("\n\n" + logo + "\n\n")

play_again = 'y'

while ((play_again == 'y')):

    list_words = ['rainbow', 'computer', 'science', 'injury', 'wizard', 'cycle', 'gigabite', 'rectangle', 'zombie', 'puzzle',
    		'mathematics', 'player', 'water', 'board', 'broom', 'company', 'india', 'everest', 'gamer', 'confident', 'matrix']
    
    random_index = random.randint(0,len(list_words))
    word = list_words[random_index]
    
    print("\nStarting the Game......")
    time.sleep(1)
    print("\nGuess the characters :)\n")
    
    guess = ''
    
    turns = 10
    
    while turns > 0:
    	
    	wrong = 0
    	
    	for char in word:
    		
    		if char in guess:
    			print(char, end = "")
    			
    		else:
    			print("*", end = "")
    			wrong += 1
    	print("")		
    
    	if wrong == 0:
            print("\n" + win + "\n")
            break
    	
    	guess_another = input("guess a character: ").lower()
    	guess += guess_another
    	
    	if guess_another not in word:
    		turns -= 1
    		print("You have", + turns, 'more guesses left..')
    		
    		if turns == 0:
    			print("\n" + lose + "\n" + "The word was :- " + word + "\n")
            
    
    play_again = input("Wants to play another Game(y/n).. ")
    play_again.lower()
    if (play_again == 'n'):
        print("Closing the Game....")
        time.sleep(1)
            
