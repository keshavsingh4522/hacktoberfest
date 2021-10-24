# ******************************** This is a snake, water, gun game ************************************

# Importing Libraries
from datetime import datetime
import random
import time

# Welcoming the user...
print("\nWelcome to SNAKE, WATER and GUN game by Sachin Dabhade\n")
name = input("Enter your name: \n")
print("\nHello " + name.capitalize() + "! Best of Luck!\n")
time.sleep(1)
print("The game is about to start!\n  Let's play and win!\n\n")
time.sleep(1)

# This will check that what input is given by user/human
def human_input():
    if x == "s":
        return "Snake"
    elif x == "w":
        return "Water"
    else:
        return "Gun"

# This will check that what input is choose by the computer
def computer_input():
    if e == "s":
        return "Snake"
    elif e == "w":
        return "Water"
    else:
        return "Gun"

# This is body of the program when the user wins
def body():
    print(f"Your guess is {human_input()} and computer guess is {computer_input()}")
    print("Congratulation.. You Won")
    print(f"Your points are {human_points} and computer points are {computer_points}")

# This is the 2nd body of program when the computer wins
def body_2():
    print(f"Your guess is {human_input()} and computer guess is {computer_input()}")
    print("Sorry.. Computer Won")
    print(f"Computer points are {computer_points} and human points are {human_points}")

# This is the best part of program that will record the starting time of program and the result of program
def record(winner, points, result):
    with open("record.txt", "a") as f:
        f.write(f"The SNAKE, WATER and GUN game is played by {name} on {datetime.now()} and {winner} {result} by {points} points\n")

# This is the main programme...
if __name__ == '__main__':
    
    elements = ("s", "w", "g")
    print("\t\t\t\t\tSnake, Water and Gun Game...\n  || \'S\' for snake || \'W\' for water || \'G\' for gun ||\n")
    
    # users necessary elements
    no_of_choises = 10
    choises = 0
    human_points = 0
    computer_points = 0

    # while loop is applied
    while choises < no_of_choises:
        inp = input("Please.. Enter your choice :  ")
        e = random.choice(elements)
        x = inp.lower()

        if x == e:
            print("This is draw because of same choises...Please try again..")
            print(f"Your guess is {human_input()} and computer guess is {computer_input()}")
            print(f"Your points are {human_points} and computer points are {computer_points}")

        elif x == "s" and e == "w":
            human_points = human_points + 1
            body()

        elif x == "w" and e == "g":
            human_points = human_points + 1
            body()

        elif x == "g" and e == "s":
            human_points = human_points + 1
            body()

        elif x == "s" and e == "g":
            computer_points = computer_points + 1
            body_2()

        elif x == "g" and e == "w":
            computer_points = computer_points + 1
            body_2()

        elif x == "w" and e == "s":
            computer_points = computer_points + 1
            body_2()

        else:
            print("Invalid input\nPlease check your input")

        choises = choises + 1
        print(f"{no_of_choises - choises} chances is left out off {no_of_choises} \n\n")
    
    print("Game Over...!")

    if computer_points > human_points:
        print(f"Sorry You have lost the game by {computer_points - human_points} points")
        record(name, computer_points-human_points, 'lost')

    elif computer_points < human_points:
        print(f"Congratulation You have Won the game by {human_points - computer_points} points")
        record(name, human_points-computer_points, 'won')

    else:
        print("Sorry...Both have same points...So this is a tie match")
