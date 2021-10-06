def mm(m1,m2):
    if len(m1[0])!=len(m2):
        print("Matrices not compatible for multiplication")
        return
    result=[[0 for i in range(len(m2[0]))] for j in range(len(m1))]
    for row in range(len(m1)):
        for col in range(len(m2[0])):
            for temp in range(len(m2)):
                result[row][col]+=m1[row][temp]*m2[temp][col]
    return result
