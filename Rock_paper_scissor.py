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
games_images = [rock, paper, scissors]

user_choice = int(input("Type '0' for rock , '1' for paper and 2 for 'scissor' : "))
print(games_images[user_choice])

computer_choice = random.randint(0, 2)
print(games_images[computer_choice])

if user_choice == 0 and computer_choice == 1:
    print("You Lose! ")
elif user_choice == 1 and computer_choice == 2:
    print("You Lose! ")
elif user_choice == 2 and computer_choice == 0:
    print("You Lose! ")
elif user_choice == 0 and computer_choice == 2:
    print("You Win! ")
elif user_choice == 2 and computer_choice == 1:
    print("You Win! ")
elif user_choice == 1 and computer_choice == 0:
    print("You Lose! ")
else:
    print("Its a Draw! ")
