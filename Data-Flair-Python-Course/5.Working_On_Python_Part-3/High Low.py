def high_low(n):
    for row in range(1,n+1):
        for col in range(row,n+1):
            print(col,end=' ')
        for col in range(n-1,row-1,-1):
            print(col,end=' ')
        print()
