# A Program for multiplication of two matrices of any order

# Let first matrix is a 3x4 matrix
A = [[10,4,6,12],
    [9,3,7,1],
    [12,8,2,5]]

# Second matrix is a 4x3 matrix
B = [[5,2,4],
    [9,1,7],
    [3,8,6],
    [6,1,8]]


# So Resultant matrix will be a 3x3 matrix
result = [[0,0,0],
         [0,0,0],
         [0,0,0]]

# Matrix multiplication
for m in range(len(A)):
   for n in range(len(B[0])):
       for o in range(len(B)):
           result[m][n] += A[m][o] * B[o][n]

for r in result:
   print(r)
