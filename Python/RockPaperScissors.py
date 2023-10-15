print("////WELCOME TO ROCK, PAPER, SCISSORS GAME\\\\\\\\")
n = 0  # no. of games
comwin = 0  # no. of win by computer
playwin = 0  # no. of win by player
name = input("\n\nWhat is your name?\n")
c = input("\nHow many rounds do you want\n")
f = int(c) - 1
print("LETS BEGIN"
      "\nType 'r' for Rock"
      "\nType 'p' for Paper"
      "\nType 's' for Scissors")
while (n < f + 1):
    import random
    import time

    option = ["rock", "paper", "scissor"]
    compu = random.choice(option)

    player = input("\nWhat do u want to play?\n")
    cap = player.capitalize()
    if (compu == "rock" and cap == "S") or (compu == "paper" and cap == "R") or (compu == "scissor" and cap == "P"):
        print("Please wait.........")
        time.sleep(1)
        print(f"Computer played : {compu}")
        print("\n^^^COMPUTER WINS THIS ROUND ^^^")
        comwin += 1
        print("\nComputer has won", comwin, "rounds")
        if comwin > (f / 2):
            break



    elif (compu == "rock" and cap == "P") or (compu == "scissor" and cap == "R") or (compu == "paper" and cap == "S"):
        print("Please wait.........")
        time.sleep(1)
        print(f"Computer played : {compu}")
        print("\n^^^YOU WIN THIS ROUND^^^")
        playwin += 1
        print("\nYou have won", playwin, "rounds")
        if playwin > (f / 2) and playwin != (f/2):
            break



    elif (compu == "rock" and cap == "R") or (compu == "scissor" and cap == "S") or (compu == "paper" and cap == "P"):
        print("Please wait.........")
        time.sleep(1)
        print(f"Computer played : {compu}")
        print("\n^^^THIS ROUND WAS DRAW^^^")

    elif n == f:
        break
    else:
        print("Invalid")
        continue

    print(f"Number of rounds Remaining : {f - n}")
    n = n + 1

if playwin > comwin:
    print("\n////CONGRATS YOU WIN GAME\\\\\\\\")
elif comwin > playwin:
    print("\n////YOU LOST THE GAME, COMPUTER WINS XD\\\\\\\\")
else:
    print("\n////THE GAME IS DRAW\\\\\\\\ ")



print(f"No. of round Computer won : {comwin}")
print(f"No. of round {name} won : {playwin}")

print("THANKS FOR PLAYING")
