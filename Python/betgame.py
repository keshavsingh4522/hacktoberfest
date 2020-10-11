from random import randint as baya
from time import sleep

bet = input("Place your bet(Small,Large): ")
money = int(input("Enter your bet money: "))

while True:

        givenrange = input("Enter a range separated by hyphen: \n")
        num = int(input("Enter a number (choose wisely): "))

        reqrange = givenrange.split("-")
        x = int(reqrange[0])
        y = int(reqrange[1])

        randomnum = baya(x,y)

        print ("Wait! Wait! Wait!")
        for i in range(6):
                print(".")
                sleep(1)
        print ("Computer gote choose kala number:",randomnum)
        print ("Your Number:",num)

        if num == randomnum:
                print("Congrats! You Won")
                print("Your price has been doubled")
                if bet == 'small':
                        money += 20
                elif bet == 'large':
                        money += 100
                print("Your money left:", money)
        else:
                print("You Noob Loser")
                print("You have less money now")
                if bet == 'small':
                        money -= 5
                elif bet == 'large':
                        money -= 25
                print("Your money left:",money)

        response = input("Do you wish to continue? Y/N: ")
        if response == 'Y':
                continue
        else:
                print("You Noob Loser, NO playing More")
                break

