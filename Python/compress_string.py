A= [x for x in input("Enter a string: ")]
blocks= []
seg= ""
for i in range(len(A)):
    c= A[i]
    seg= seg+c
    try:
        if A[i]!=A[i+1]:
            blocks.append(seg)
            seg=""
    except:
        blocks.append(seg)
for block in blocks:
    tup= (len(block), int(block[0]))
    print(tup, end=" ")
