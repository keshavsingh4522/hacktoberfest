import random
lst=("rock","paper","scissor")

#Here a is the choice for computer
print("Welcome to the game of Rock, paper, scissor.\n Its You versus the computer. \n There will be 10 rounds in total.\n ***GOOD LUCK***")
i=0
wins=0
losses=0
draws=0
while(i<11):
    a=random.choice(lst)
    b=input("Choose from the following: R(rock), P(paper), S(scissor): ") #input value of player
    if b=="R" and a=="rock":
        print("You chose for " ,b , "and the computer chose for " ,a , "\n Its a draw." )
        draws= draws+1
        i=i+1
        continue
    elif b=="R" and a=="paper":
        print("You chose for " ,b , "and the computer chose for " ,a , "\n You lose." )
        losses= losses+1
        i=i+1
        continue
    elif b=="R" and a=="scissor":
        print("You chose for " ,b , "and the computer chose for " ,a , "\n You Win." )
        wins= wins+1
        i=i+1
        continue
    elif b=="P" and a=="rock":
        print("You chose for " ,b , "and the computer chose for " ,a , "\n You Win." )
        wins= wins+1
        i=i+1
        continue
    elif b=="P" and a=="paper":
        print("You chose for " ,b , "and the computer chose for " ,a , "\n Its a draw." )
        draws= draws+1
        i=i+1   
        continue 
    elif b=="P" and a=="scissor":
        print("You chose for " ,b , "and the computer chose for " ,a , "\n You lose." )
        losses= losses+1
        i=i+1
        continue
    elif b=="S" and a=="rock":
        print("You chose for " ,b , "and the computer chose for " ,a , "\n You lose." )
        losses= losses+1
        i=i+1
        continue
    elif b=="S" and a=="paper":
        print("You chose for " ,b , "and the computer chose for " ,a , "\n You Win." )
        wins= wins+1
        i=i+1   
        continue 
    elif b=="S" and a=="scissor":
        print("You chose for " ,b , "and the computer chose for " ,a , "\n Its a draw." )
        draws= draws+1
        i=i+1
        continue

if i==11:
    print("No. of wins= " , wins , "\nNo. of losses= " , losses , "\nNo. of draws= " , draws ,"\n***THANKS FOR PLAYING***")

