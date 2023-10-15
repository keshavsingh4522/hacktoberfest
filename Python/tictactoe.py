# ____--Global Variable--____
game_still_going = True
current_player = "X"
winner = None

# Defining a Board
board = ["-", "-", "-",
         "-", "-", "-",
         "-", "-", "-"]


# Display the initial board
def display_board():
    print(board[0] + " | " + board[1] + " | " + board[2])
    print(board[3] + " | " + board[4] + " | " + board[5])
    print(board[6] + " | " + board[7] + " | " + board[8])

# Handling a turn of a particular player
def handle_turn(player):
    print(player + " turn...")
    position = input("Choose position from 1-9: ")
    valid = False
    while not valid:

        while position not in ["1", "2", "3", "4", "5", "6", "7", "8", "9"]:
            position = input("Invalid Output... Choose position from 1-9: ")

        position = int(position) - 1
        if board[position] == "-":
            valid = True
        else:
            print("You can't go there")

    board[position] = player

    display_board()

# Check If Game over 
def check_if_game_over():
    # Check for win
    check_for_winner()
    # Check for tie
    check_for_tie()
    return

#Check for the winner 
def check_for_winner():
    global winner
    # check rows
    row_winner = check_row()
    # check columns
    column_winner = check_columns()
    # check diagonals
    diagonal_winner = check_diagonals()

    # If there is a row winner modify winner to row_winner {value}
    if row_winner:
        winner = row_winner

    # if there is a column winner modify the winner to column_winner{value}
    elif column_winner:
        winner = column_winner

    # if there is a diagonal winner modify the winner to diagonal_winner{value}
    elif diagonal_winner:
        winner = diagonal_winner
    else:
        winner = None
    return


def check_row():
    # Set up a global variables
    global game_still_going

    row_1 = board[0] == board[1] == board[2] != "-"
    row_2 = board[3] == board[4] == board[5] != "-"
    row_3 = board[6] == board[7] == board[8] != "-"
    if row_1 or row_2 or row_3:
        game_still_going = False

    # Returning the value of 'X' or 'O'
    if row_1:
        return board[0]
    elif row_2:
        return board[3]
    elif row_3:
        return board[6]
    return


def check_columns():
    # Set up a global variables
    global game_still_going

    column_1 = board[0] == board[3] == board[6] != "-"
    column_2 = board[1] == board[4] == board[7] != "-"
    column_3 = board[2] == board[5] == board[8] != "-"
    if column_1 or column_2 or column_3:
        game_still_going = False

    # Returning the value of 'X' or 'O'
    if column_1:
        return board[0]
    elif column_2:
        return board[1]
    elif column_3:
        return board[2]
    return


def check_diagonals():
    # Set up a global variables
    global game_still_going

    diagonal_1 = board[0] == board[4] == board[8] != "-"
    diagonal_2 = board[2] == board[4] == board[6] != "-"

    if diagonal_1 or diagonal_2:
        game_still_going = False

    # Returning the value of 'X' or 'O'
    if diagonal_1:
        return board[0]
    elif diagonal_2:
        return board[6]
    return


# Check whether game tie
def check_for_tie():
    global game_still_going
    if "-" not in board:
        game_still_going = False
    return


# Flip the turn if 'O' TO 'X' elif 'X' to 'O'
def flip_player():
    global current_player
    if current_player == "X":
        current_player ="O"
    elif current_player == "O":
        current_player = "X"
    return


# Main function to play the game
def play_game():
    # Display initial board
    display_board()

    while game_still_going:
        # Handle turn of a single player
        handle_turn(current_player)

        # Check if game is over
        check_if_game_over()

        # Flip the player
        flip_player()
    if winner == "X" or winner == "O":
        print(f"{winner}  Won...")

    elif winner == None:
        print("Tie...")


play_game()
