#variables

player="X"
result=None
cont= True

#starting the game

board = ['-','-','-','-','-','-','-','-','-']
print("Starting the game... [ TIC TAC TOE ]")

#board

def full_board():
    print()
    print("                      (POSITIONS)")
    print(board[0]+' |',board[1]+' |',board[2],"             1 | 2 | 3 ")
    print(board[3]+' |',board[4]+' |',board[5],"             4 | 5 | 6 ")
    print(board[6]+' |',board[7]+' |',board[8],"             7 | 8 | 9 ")
    print()

full_board()
print("X's turn...")
#input positions

def position():
    global player
    global cont
    pos=input("Enter your liked position from 1-9 :")
    while pos not in ("1","2","3","4","5","6","7","8","9"):
        pos=input("Enter your liked position from 1-9 :")
    pos=int(pos)-1
    if board[pos]!="-":
        print("You cant go there, TRY AGAIN...")
        cont=False
    else:
        board[pos]=player
        full_board()
        cont=True

#win/tie check 

def game_over():
    global result
    result= None
    row1= board[0]==board[1]==board[2]!="-"
    row2= board[3]==board[4]==board[5]!="-"
    row3= board[6]==board[7]==board[8]!="-"
    col1= board[0]==board[3]==board[6]!="-"
    col2= board[1]==board[4]==board[7]!="-"
    col3= board[2]==board[5]==board[8]!="-"
    dig1= board[0]==board[4]==board[8]!="-"
    dig2= board[2]==board[4]==board[6]!="-"
    if row1 :
        result= True
        print("Congratulations... Player",board[0]+"'s won")
    elif row2 :
        result= True
        print("Congratulations... Player",board[3]+"'s won")
    elif row3 :
        result= True
        print("Congratulations... Player",board[6]+"'s won")
    elif col1 :
        result= True
        print("Congratulations... Player",board[0]+"'s won")
    elif col2 :
        result= True
        print("Congratulations... Player",board[1]+"'s won")
    elif col3 :
        result= True
        print("Congratulations... Player",board[2]+"'s won")
    elif dig1 :
        result= True
        print("Congratulations... Player",board[0]+"'s won")
    elif dig2 :
        result= True 
        print("Congratulations... Player",board[2]+"'s won")
    elif "-" not in board :
        result = True
        print("Game Tied")
    return()

#player change 

def flip():
    global player
    global cont
    if player == "X" and result!= True and cont==True:
        print("O's turn...")
        player="O"
    elif player == "O" and result!= True and cont==True:
        print("X's turn...")
        player="X"

#restaring the game

def restart():
    global board
    board = ['-','-','-','-','-','-','-','-','-']
    print("==========================================")
    print()
    print("Starting the game... [ TIC TAC TOE ]")
    full_board()
    print("X's turn...")
#game loop
    
while True:       
    while result!= True:
        position()
        game_over()
        flip()
    print()
    loop=input("You want to replay the game (y/n): ")
    if loop=="Y" or loop=="y":
        result=None
        restart()
    elif loop=="N" or loop=="n":
        break
   
#end
