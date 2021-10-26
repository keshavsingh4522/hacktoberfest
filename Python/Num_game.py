
def factors(x):
  factors=[]
  if x == 1:
    factors.append(x)
    return factors
  
  for i in range(x-1,0,-1):
    if x % i == 0:
      factors.append(i)
  return factors
           

def computer_player(num,name):
  if num == 1:
    return 0

  arr = factors(num)
  print("N =",num,end = ' | ')
  if num % 2 == 0:
    for x in arr:
      if x % 2 != 0:
        print (name,"Play =>",num,"-",x,"=",num-x)
        return num-x
  elif num %2 != 0:
      print (name,"Play =>",num,"-",1,"=",num-1)
      return num-1

def humanPlayer(num):
  if num == 1:
    return 0
  arr = []
  arr = factors(num)
  print("N =",num,end = ' | ')
  print("factors of:",num,"are",arr)
  #print(arr)
  
  while True:
    opt = int(input('Enter one of the following factors of the number '))
    if opt in arr:
      return num-opt
    else:
      print("try again")

def rules_of_game():
  print("-----------------------Rules-----------------------")
  print("1. Two players are required and player 1 plays first, \n   and the two players alternate.")
  print("2. On the player's turn, a player can subtract from N \n   any proper divisor (not equal to N) of N. The number thus\n   obtained is the new N.")
  print("3. The player who cannot make a move in his/her turn loses the game.")
  print("Note: N must be greater than 0.")
  print("\nHave Fun!\n")

def inputs_game(opt):
  n = int(input('Enter the N numbers to start: '))
  if opt == 1:
    player1_name = input('Enter Computer Name: ')
    player2_name = input('Enter player Name: ')
  if opt == 2:
    player1_name = input('Enter player Name: ')
    player2_name = input('Enter Computer Name: ')
  if opt == 3:
    player1_name = input('Enter player 1 Name: ')
    player2_name = input('Enter player 2 Name: ')
  if opt == 4:
    player1_name = input('Enter Computer 1 Name: ')
    player2_name = input('Enter Computer 2 Name: ')


  return (n,player1_name,player2_name)


def game_human_vs_human(n,player1,player2):
  while n>0:
    print(player1,"Turns")
    n=humanPlayer(n)
    if n==0:
      print(player1, "can't move")
      print(player2,"Wins")
      break
    print(player1,"Turns")
    n=humanPlayer(n)
    if n==0:
      print(player2, "can't move")
      print(player1,"Wins")
      break

def game_human_vs_computer(n,player1,player2):
  while n>0:
    print(player1,"Turns")
    n=humanPlayer(n)
    if n==0:
      print(player1, "can't move")
      print(player2,"Wins")
      break
    print(player2,"Turns")
    n=computer_player(n,player2)
    if n==0:
      print(player2, "can't move")
      print(player1,"Wins")
      break

def game_computer_vs_human(n,player1,player2):
  while n>0:
    print(player1,"Turns")
    n=computer_player(n,player1)
    if n==0:
      print(player1, "can't move")
      print(player2,"Wins")
      break
    print(player2,"Turns")
    n=humanPlayer(n)
    if n==0:
      print(player2, "can't move")
      print(player1,"Wins")
      break

def game_computer_vs_computer(n,player1,player2):
  while n>0:
    print(player1,"Turns")
    n=computer_player(n,player1)
    if n==0:
      print(player1, "can't move")
      print(player2,"Wins")
      break
    print(player2,"Turns")
    n=computer_player(n,player2)
    if n==0:
      print(player2, "can't move")
      print(player1,"Wins")
      break

#mode of game
def game():
  rules_of_game()

  print("Chose your mode game ")
  print("1 - Computer vs Human")
  print("2 - Human vs Computer")
  print("3 - Human vs Human")
  print("4 - Computer vs Computer")
  

  i=0
  while True:
    opt = int(input('Enter your choose: '))
    
    if (opt < 5):
      start = inputs_game(opt)
    if opt == 1:
      game_computer_vs_human(start[0],start[1],start[2])
      return
    elif opt == 2:
      game_human_vs_computer(start[0],start[1],start[2])
      return
    elif opt == 3:
      game_human_vs_human(start[0],start[1],start[2])
      return
    elif opt == 4:
      game_computer_vs_computer(start[0],start[1],start[2])
      return
    else:
      if i==0:
        print("YOU MUST PLAY!!!! (at least once please)")
      elif i < 3:
        print("Pleace!!!")
      else:
        print("Well, bye and good luck")
        return
    i +=1

#Start of Game
game()


