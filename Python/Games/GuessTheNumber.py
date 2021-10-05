                        # GUESSING A RANDOM GENERATED NUMBER GAME PROGRAM

import random
rno=random.randint(1,100)
guesses=0
uguess=None
while(uguess!=rno):
    uguess=int(input("Enter number: "))
    guesses+=1
    if(uguess==rno):
        print("You guessed it right!")
    else:
        if(uguess>rno):
            print("You guessed it wrong! Enter a smaller number.")
        else:
            print("You guessed it wrong! Enter a larger number.")
print(f"You guessed the number in {guesses} guesses.")

