

import test_random_word_api

image_win = """
  \O/  
   |
  / \ 
"""
images= [

"""
       |
       |
       |
       |
 ______|
""",
"""
    ---|
       |
       |
       |
 ______|
""",
"""
   |---|
       |
       |
       |
 ______|
""",
"""
   |---|
   O   |
       |
       |
 ______|
""",
"""
   |---|
   O   |
   |   |
       |
 ______|
""",
"""
   |---|
   O   |
  /|   |
       |
 ______|
""",
"""
   |---|
   O   |
  /|\  |
       |
 ______|
""",
"""
   |---|
   O   |
  /|\  |
  /    |
 ______|
""",
"""
   |---|
   O   |
  /|\  |
  / \  |
 ______|
"""
]






def print_rules():
    print(""" 
            ------------------------------ Hangman ------------------------------
            Hangman is a word Guessing game. Each time you are given a random word.
			You have to guess it alphabet by alphabet.

			A total of 8 turns is given to guess the entire word correctly.
			A wrong guess reduces the number of turns remaining.

			You may guess the entire word in a go. In such case if word is correct you win, otherwise you loose directly even if few turns are still left.

			The state of the game is displayed w.r.t the images of a human being hanged.
			It starts with an empty post and ends with the complete human form when you loose.


			    ---|
                   |
       			   |	
			       |
			 ______|



			   |---|
			   O   |
			  /|\  |
			  / \  |
			 ______|

			------------------------------ Hangman ------------------------------""")




def play_game():
  guess=[]
  rnd_wrd=test_random_word_api.get_word().upper()
  #print(rnd_wrd)  -- remove the comment to check the random word generated
  rem_turns=8
  correct_guess=list('_'*len(rnd_wrd))
  wrong=0
  while True:
    
            
    print("Remaining turns: ",rem_turns-wrong,"\t",  "Guesses: ", guess)
    user_guess=input("Guess alphabet or full word: ").upper()
    if len(user_guess)==1:
      guess.append(user_guess)

      



      count=0
      for b in range(len(rnd_wrd)):
        if rnd_wrd[b]==user_guess:
          correct_guess[b]=rnd_wrd[b]
          print("Correct guess !! ",' '.join(correct_guess),'\t\t' ,images[wrong])
        


        if (''.join(correct_guess))==rnd_wrd:
          print(image_win,"\t","You WINN!!! the word is ",rnd_wrd)
          exit()




        if user_guess not in rnd_wrd:
          wrong+=1
          print('\n\t\t\t',images[wrong],'\t\t\t\t',' '.join(correct_guess),"Nope wrong guess!!! \n\n\n")
          break

        if wrong==8:
          print("Out of turns !!! You lose ")
          exit()
                      
      
    else:
      if user_guess==rnd_wrd:
        print(image_win,"\t","You WINN!!! the word is ",rnd_wrd)
        break

      else:
        print("You LOSE!!!")
        break


main_menu = """

1. Play
2. Rules
3. Exit
"""
print(main_menu)
user_option=int(input("Give input (1 - 3): "))

if user_option==1:
  play_game()

if user_option==2:
  print_rules()
  print(main_menu)
  user_option=int(input("Give input (1 - 3): "))

if user_option==3:
  exit()

