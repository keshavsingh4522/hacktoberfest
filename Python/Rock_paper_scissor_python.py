#Chandrajit
import random
rock = '''
    _______
---'   ____)
      (_____)
    r (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
        p _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       s__________)
      (____)
---.__(___)
'''
user_choice= int(input("What do you choose? Type 0 for Rock, 1 for paper, 2 for scissor "))

grab_images=[rock,paper,scissors]
ran=random.randint(0,2)

if user_choice>=3 or user_choice <0:
 print("You typed invalid number you lose.")
elif user_choice==0 and ran==2:
  print("You win")
elif ran==0 and user_choice==2:
  print("You lose")
elif ran>user_choice:
  print("You lose")  
elif user_choice>ran:
  print("You win, Thank you")  
elif ran==user_choice:
  print("It's a draw")


if (user_choice >=3 or user_choice<0):
  print("invalid move.")
else:
  print(grab_images[user_choice])

print("Computer choice:-\n")
print(f"computer choice {ran}")
if ran==0:
  print(rock)
if ran==1:
  print(paper)
if ran==2:
  print(scissors)
