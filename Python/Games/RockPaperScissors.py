                                # ROCK PAPER SCISSORS GAME PROGRAM
import random
def gameWin(comp,you):   
        if comp==you:
            return None
        elif(comp=="r"):
            if (you =="p"):
             return True
            elif (you =="s"):
             return False
        elif(comp=="p"):
            if (you =="s"):
                return True
            elif (you =="r"):
                return False 
        elif(comp=="s"):
            if (you =="r"):
                return True
            elif (you =="p"):
                return False
print("Computer's Turn: Rock(r), Paper(p) or Scissors(s)?")

randNO=random.randint(1,3)
if randNO==1:
        comp = "r"
elif randNO==2:
        comp = "p"
elif randNO==3:
        comp = "s"
you= input("Player's turn: Rock(r), Paper(p) or Scissors(s)?")

a=gameWin(comp,you)
print(f"Computer chose: {comp}")
print(f"You chose: {you}")
if (a==None):
        print("The game is a Tie!")
elif (a==True):
        print("You Win!")
elif (a==False):
        print("You Lose!")
