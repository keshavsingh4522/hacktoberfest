from IPython.display import clear_output

   def display_board(board):
       clear_output()
       print("     |     |    ")
       print('  '+board[1]+'  '+'|'+'  '+board[2]+'  '+'|'+'  '+board[3])
       print("_____|_____|_____")
       print("     |     |    ")
       print('  '+board[4]+'  '+'|'+'  '+board[5]+'  '+'|'+'  '+board[6])
       print("_____|_____|_____")
       print("     |     |    ")
       print('  '+board[7]+'  '+'|'+'  '+board[8]+'  '+'|'+'  '+board[9])
       print("     |     |    ")
   def player_input():

       marker = ''

       #keep asking the user for the input ie, X or O 
       while marker != 'X' and marker!='O':
           marker=input("Player 1 choose x or o: ")

       player1=marker

       if player1=='X':
           player2='O'
       else:
           player2='X'

       return (player1,player2)
   def place_marker(board,marker,position):
       board[position]=marker
   def win_check(board,mark):
       return ((board[7] == mark and board[8] == mark and board[9] == mark) or # bottom row
       (board[4] == mark and board[5] == mark and board[6] == mark) or # midddle row
       (board[1] == mark and board[2] == mark and board[3] == mark) or # first row
       (board[7] == mark and board[4] == mark and board[1] == mark) or # down the middle
       (board[8] == mark and board[5] == mark and board[2] == mark) or # down the middle
       (board[9] == mark and board[6] == mark and board[3] == mark) or # down the right side
       (board[7] == mark and board[5] == mark and board[3] == mark) or # diagonal
       (board[9] == mark and board[5] == mark and board[1] == mark)) # diagonal
   import random

   def choose_first():
       if random.randint(1,2)==1:
           return 'PLAYER 1'
       else:
           return 'PLAYER 2'
    def space_check(board, position):
       if board[position]=='' or board[position]==' ':
           return True
       else:
           return False
    def full_board_check(board):
       for i in range(1,9):
           if space_check(board,i):
               return False
       return True
    def player_choice(board):
       position=0

       while position not in [1,2,3,4,5,6,7,8,9] or not space_check(board,position):
           position = int(input('Choose your next position: (1-9)'))

       return position
   def replay():
       play=input("do you want to continue playing? Y/N")
       play=play.upper()

       if play=='Y':
           return True
       else:
           return False
   print ('WELCOME TO TIC TIC TOE!!!')

   while True:

       theboard=[' ']*10
       player1_marker,player2_marker= player_input()
       turn=choose_first()
       print(turn + 'will go first!')

       play_game=input('Are you ready to play? Enter Y/N')
       if play_game.upper()=='Y':
           game_on=True
       else:
           game_on=False

       while game_on:
           if turn=='Player 1':

               #PLAYER1'S TURN
               display_board(theboard)
               position=player_choice(theboard)
               place_marker(theboard,player1_marker,position)

               if win_check(theboard, player1_marker):
                   display_board(theboard)
                   print('CONGRATULATIONS!!! Player 1 Has Won The Game!')
                   game_on=False
               else:
                   if full_board_check(theboard):
                       diplay_board(theboard)
                       print('The game is a draw!')
                       break
                   else:
                       turn='Player 2'


           else:

               #PLAYER2'S TURN
               display_board(theboard)
               position=player_choice(theboard)
               place_marker(theboard,player2_marker,position)

               if win_check(theboard, player2_marker):
                   display_board(theboard)
                   print('CONGRATULATION!!! Player 2 Has Won The Game!')
                   game_on=False
               else:
                   if full_board_check(theboard):
                       display_board(theboard)
                       print('The game is a draw!')
                       break
                   else:
                       turn='Player 1'



           if not replay():
               break
