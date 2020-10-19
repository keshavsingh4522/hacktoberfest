# simple program to perform roll dice
import random

min = 1
max = 6
roll = 'y'

while roll == 'y':
    print('rolling the dice. . . ')
    print('the dice is : ') 
    print(random.randint(min, max))

    roll = input('roll again? y/n : ')