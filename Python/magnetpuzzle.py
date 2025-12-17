# Utility function to print solution
def printSolution(board):
    for i in range(M):
        for j in range(N):
            print(board[i][j], end=' ')
        print()
 
 
# Utility function to count the total number of characters `ch` in current column `j`
def countInColumns(board, ch, j):
    count = 0
    for i in range(M):
        if board[i][j] == ch:
            count = count + 1
    return count
 
 
# Utility function to count the total number of characters `ch` in current row `i`
def countInRow(board, ch, i):
    count = 0
    for j in range(N):
        if board[i][j] == ch:
            count = count + 1
    return count
 
 
# Function to check if it is safe to put `ch` at `board[row][col]`
def isSafe(board, row, col, ch, top, left, bottom, right):
 
    # check for adjacent cells
    if ((row - 1 >= 0 and board[row - 1][col] == ch) or
            (col + 1 < N and board[row][col + 1] == ch) or
            (row + 1 < M and board[row + 1][col] == ch) or
            (col - 1 >= 0 and board[row][col - 1] == ch)):
        return False
 
    # count character `ch` in the current row
    rowCount = countInRow(board, ch, row)
 
    # count character `ch` in the current column
    colCount = countInColumns(board, ch, col)
 
    # if the given character is `+`, check `top[]` and `left[]`
    if ch == '+':
 
        # check top
        if top[col] != -1 and colCount >= top[col]:
            return False
 
        # check left
        if left[row] != -1 and rowCount >= left[row]:
            return False
 
    # if the given character is `-`, check `bottom[]` and `right[]`
    if ch == '-':
 
        # check bottom
        if bottom[col] != -1 and colCount >= bottom[col]:
            return False
 
        # check left
        if right[row] != -1 and rowCount >= right[row]:
            return False
 
    return True
 
 
# Function to validate the configuration of an output board
def validateConfiguration(board, top, left, bottom, right):
 
    # check top
    for i in range(N):
        if top[i] != -1 and countInColumns(board, '+', i) != top[i]:
            return False
 
    # check left
    for j in range(M):
        if left[j] != -1 and countInRow(board, '+', j) != left[j]:
            return False
 
    # check bottom
    for i in range(N):
        if bottom[i] != -1 and countInColumns(board, '-', i) != bottom[i]:
            return False
 
    # check right
    for j in range(M):
        if right[j] != -1 and countInRow(board, '-', j) != right[j]:
            return False
 
    return True
 
 
# The main function to solve the Bipolar Magnets puzzle
def solveMagnetPuzzle(board, row, col, top, left, bottom, right, rules):
 
    # if the last cell is reached
    if row >= M - 1 and col >= N - 1:
        return validateConfiguration(board, top, left, bottom, right)
 
    # if the last column of the current row is already processed,
    # go to the next row, the first column
    if col >= N:
        col = 0
        row = row + 1
 
    # if the current cell contains `R` or `B` (end of horizontal
    # or vertical slot), recur for the next cell
    if rules[row][col] == 'R' or rules[row][col] == 'B':
 
        if solveMagnetPuzzle(board, row, col + 1, top, left, bottom, right, rules):
            return True
 
    # if the horizontal slot contains `L` and `R`
    if rules[row][col] == 'L' and rules[row][col + 1] == 'R':
 
        # put (`+`, `-`) pair and recur
        if (isSafe(board, row, col, '+', top, left, bottom, right) and
                isSafe(board, row, col + 1, '-', top, left, bottom, right)):
            board[row][col] = '+'
            board[row][col + 1] = '-'
 
            if solveMagnetPuzzle(board, row, col + 2, top, left, bottom, right, rules):
                return True
 
            # if it doesn't lead to a solution, backtrack
            board[row][col] = 'X'
            board[row][col + 1] = 'X'
 
        # put (`-`, `+`) pair and recur
        if (isSafe(board, row, col, '-', top, left, bottom, right) and
                isSafe(board, row, col + 1, '+', top, left, bottom, right)):
            board[row][col] = '-'
            board[row][col + 1] = '+'
 
            if solveMagnetPuzzle(board, row, col + 2, top, left, bottom, right, rules):
                return True
 
            # if it doesn't lead to a solution, backtrack
            board[row][col] = 'X'
            board[row][col + 1] = 'X'
 
    # if the vertical slot contains `T` and `B`
    if rules[row][col] == 'T' and rules[row + 1][col] == 'B':
 
        # put (`+`, `-`) pair and recur
        if (isSafe(board, row, col, '+', top, left, bottom, right) and
                isSafe(board, row + 1, col, '-', top, left, bottom, right)):
            board[row][col] = '+'
            board[row + 1][col] = '-'
 
            if solveMagnetPuzzle(board, row, col + 1, top, left, bottom, right, rules):
                return True
 
            # if it doesn't lead to a solution, backtrack
            board[row][col] = 'X'
            board[row + 1][col] = 'X'
 
        # put (`-`, `+`) pair and recur
        if (isSafe(board, row, col, '-', top, left, bottom, right) and
                isSafe(board, row + 1, col, '+', top, left, bottom, right)):
            board[row][col] = '-'
            board[row + 1][col] = '+'
 
            if solveMagnetPuzzle(board, row, col + 1, top, left, bottom, right, rules):
                return True
 
            # if it doesn't lead to a solution, backtrack
            board[row][col] = 'X'
            board[row + 1][col] = 'X'
 
    # ignore the current cell and recur
    if solveMagnetPuzzle(board, row, col + 1, top, left, bottom, right, rules):
        return True
 
    # if no solution is possible, return false
    return False
 
 
def magnetPuzzle(top, left, bottom, right, rules):
 
    # to store the result
    # initialize all cells by `X`
    board = [['X' for x in range(N)] for y in range(M)]
 
    # start from `(0, 0)` cell
    if not solveMagnetPuzzle(board, 0, 0, top, left, bottom, right, rules):
        print("Solution does not exist")
        return
 
    # print result if the given configuration is solvable
    printSolution(board)
 
 
if __name__ == '__main__':
 
    # indicates the count of `+` or `-` along the top (+), bottom (-),
    # left (+), and right (-) edges, respectively.
    # value of -1 indicate any number of `+` or `-` signs
    top = [1, -1, -1, 2, 1, -1]
    bottom = [2, -1, -1, 2, -1, 3]
    left = [2, 3, -1, -1, -1]
    right = [-1, -1, -1, 1, -1]
 
    # rules matrix
    rules = [
        ['L', 'R', 'L', 'R', 'T', 'T'],
        ['L', 'R', 'L', 'R', 'B', 'B'],
        ['T', 'T', 'T', 'T', 'L', 'R'],
        ['B', 'B', 'B', 'B', 'T', 'T'],
        ['L', 'R', 'L', 'R', 'B', 'B']
    ]
 
    # `M × N` matrix
    (M, N) = (len(rules), len(rules[0]))
 
    magnetPuzzle(top, left, bottom, right, rules)
