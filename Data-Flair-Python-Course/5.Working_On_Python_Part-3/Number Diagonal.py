def num_diagonal():
    for row in range(1,6):
        for col in range(1,6):
            if row==col: print(row,end='')
            else: print(0,end='')
        print()

num_diagonal()
