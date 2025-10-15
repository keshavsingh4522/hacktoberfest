def create_board():
    # Set up chess board as an 8x8 array
    board = [
        ["r", "n", "b", "q", "k", "b", "n", "r"],
        ["p", "p", "p", "p", "p", "p", "p", "p"],
        [" ", " ", " ", " ", " ", " ", " ", " "],
        [" ", " ", " ", " ", " ", " ", " ", " "],
        [" ", " ", " ", " ", " ", " ", " ", " "],
        [" ", " ", " ", " ", " ", " ", " ", " "],
        ["P", "P", "P", "P", "P", "P", "P", "P"],
        ["R", "N", "B", "Q", "K", "B", "N", "R"]
    ]
    return board

def print_board(board):
    print("\n   a b c d e f g h")
    print("  -----------------")
    for i, row in enumerate(board):
        print(str(8-i) + "|", end=" ")
        for piece in row:
            print(piece, end=" ")
        print("|" + str(8-i))
    print("  -----------------")
    print("   a b c d e f g h\n")

def parse_move(move):
    # Example move: e2e4
    if len(move) != 4:
        return None
    cols = {"a":0,"b":1,"c":2,"d":3,"e":4,"f":5,"g":6,"h":7}
    try:
        from_col, from_row, to_col, to_row = move[0], int(move[1]), move[2], int(move[3])
        return 8-from_row, cols[from_col], 8-to_row, cols[to_col]
    except (KeyError, ValueError):
        return None

def valid_move(board, fr, fc, tr, tc, turn):
    piece = board[fr][fc]
    dest = board[tr][tc]
    if piece == " " or (turn == "white" and piece.islower()) or (turn == "black" and piece.isupper()):
        return False
    # Basic move validation: allow moving to empty square or capturing opponent
    if turn == "white" and dest.isupper():
        return False
    if turn == "black" and dest.islower():
        return False
    return True

def make_move(board, fr, fc, tr, tc):
    board[tr][tc] = board[fr][fc]
    board[fr][fc] = " "

def main():
    board = create_board()
    print("Simple Chess Game")
    print_board(board)
    turn = "white"
    while True:
        move = input(f"{turn.capitalize()} move (e.g. e2e4): ").lower().strip()
        if move == "exit":
            print("Game exited.")
            break
        pos = parse_move(move)
        if not pos:
            print("Invalid input! Format: e2e4")
            continue
        fr, fc, tr, tc = pos
        if valid_move(board, fr, fc, tr, tc, turn):
            make_move(board, fr, fc, tr, tc)
            print_board(board)
            # Basic checkmate detection (ends when king captured)
            pieces = sum(row for row in board)
            if "k" not in pieces:
                print("White wins! (Black king captured)")
                break
            if "K" not in pieces:
                print("Black wins! (White king captured)")
                break
            turn = "black" if turn == "white" else "white"
        else:
            print("Invalid move or move not allowed!")

if __name__ == "__main__":
    main()
