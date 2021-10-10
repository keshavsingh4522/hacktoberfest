import random
b='y'

while(b=='y'):
  def gamewin(comp,you):
    if comp==you:
        return None
    elif comp== 'st':
        if you== 'p':
            return True
        else:
            return False
    elif comp== 'p':
        if you== 'sc':
            return True
        else:
            return False
    else:
        if you== 'st':
            return True
        else:
            return False


  print("Computer's turn: Stone(st), Paper(p), Scissor(sc)")
  randon=random.randint(1,3)
  if randon==1:
   comp='st'
  elif randon==2:
    comp='p'
  else:
    comp='sc'


  you = input("Your Turn: Stone(st), Paper(p), Scissor(sc)")

  print("Computer chose: " +comp)
  print("You chose: "+you)

  a=gamewin(comp,you)

  if a==None:
    print("Match is draw!!:)")
  elif a==True:
    print("Hurray!! You win!!:D")
  else:
    print("Alas!You lose:(")

  b=input("Do you want to play again(y/n)")
if(b=='n'):
 print("Thanks for playing :D")
 'break'
