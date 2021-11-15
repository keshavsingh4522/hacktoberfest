import random

while True:
    a=random.randint(1,100)
    b=None
    while a!=b:
        b=int(input("Guess a Number between (1-100): "))
        if a<b:
            print("Your guess is too high")
        elif a>b:
            print("Your guess is too low")
    print("Congratulations! You gussed the number correctly.")
    print()
    z=input("You want to play again (y/n): ")
    print()
    if z=="n" or z=="N":
        break

        
