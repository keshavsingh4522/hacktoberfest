#  Snake Water Gun or Rock Paper Scissor.
import random

def gameWin(comp,you):
    # If two value are equal declare a tie.
    if comp == you:
        return None
    # Check for all possibilities when computer chooses s.
    elif comp=='s':
        if you == 'w':
            return False
        else:
            return True
    # Check for all possibilities when computer chooses w.
    elif comp=='w':
        if you == 'g':
            return False
        else:
            return True
    # Check for all possibilities when computer chooses g.
    elif comp=='g':
        if you == 's':
            return False
        else:
            return True
    

randNo = random.randint(1,3)
if randNo==1:
    comp = 's'
elif randNo==2:
    comp = 'w'
else:
    comp = 'g'

you = input("Player's Turn: Snake(s) , water(w) or gun(g) ? : ")

a=gameWin(comp,you)

print(f"\nYou choose {you}\n")
print(f"computer choose {comp}\n")

if a==None:
    print("Game Draw....")
elif a==False:
    print("Computer Win !!") 
elif a==True:
    print("You win !!")
