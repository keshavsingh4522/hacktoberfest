import random
rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''

choice_of_the_player = int(input("What do you chose? Type 0 for Rock, 1 for Paper, 2 for Scissors.\n"))

if choice_of_the_player == 0:
    print(rock)
elif choice_of_the_player == 1:
    print(paper)
elif choice_of_the_player == 2:
    print(scissors)
else:
    print("INVALID NUMBER ENTERED, please enter in 0,1 or 2")

computer_choice = random.randint(0,2)

print(f"Computer chose:\n")

if computer_choice == 0:
    print(rock)
elif computer_choice == 1:
    print(paper)
else:
    print(scissors)

if computer_choice == choice_of_the_player:
    print("Draw Match")
elif (choice_of_the_player == 0 and computer_choice == 2) or (choice_of_the_player == 2 and computer_choice == 1) or ( choice_of_the_player == 1 and computer_choice == 0):
    print("You win")
else:
    print("You lose")
