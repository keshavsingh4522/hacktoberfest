# *********************** Animal Guessing Game *******************

# Importing Libraries
import random
import time
from datetime import datetime

# Initial Steps to invite in the game:
print("\nWelcome to ANIMAL GUESSING game by Sachin Dabhade\n")
name = input("Enter your name: ")
print("Hello " + name.capitalize() + "! Best of Luck!")
time.sleep(1)
print("\nThe game is about to start!\n Let's play and win!\n\n")
time.sleep(1)

# This will record all the activities in the game
def record():
    with open("record.txt", "a") as f:
        f.write(f"The ANIMAL GUESSING game is played by {name} on {datetime.now()}\n")

if __name__ == '__main__':
    
    # Initializing the variables
    chance = 5
    score = 0
    attempt = 0
    animal_list = ("Tiger", "Lion", "Giraffe", "Cheeta", "Rabbit")
    print(f"\t\tANIMAL GUESSING GAME\n\n\t\t !...GOOD LUCK...!")

    while chance > attempt:
        
        # updating the variables and geting the inputs
        animal = random.choice(animal_list)
        attempt = attempt + 1
        print(f"\nYou need at least 2 score to won the game")
        x = input("Guess the animal (Tiger, Lion, Giraffe, Cheeta, Rabbit):")
    
        # Checking the user input and the computer guess
        if x.capitalize() == animal:
            score = score + 1
            print("Congratulation... Your guess is absolutely correct...!")
    
        elif x.capitalize() in animal_list:
            print("Sorry but you can do it! Keep trying...!")
    
        else:
            print("Invalid input...!")

        print(f"The computer guess is {animal} and your guess is {x.capitalize()}")
        print(f"Your score is {score} and you have {chance - attempt} attempt remaining.")
        continue

print("Thanks For Playing!\nWe expect you will back again and enjoy our game...!\n")
record()
