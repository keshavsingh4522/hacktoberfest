# cook your dish here
def decimalToBinary(n):  
    return bin(n).replace("0b", "")
    
for _ in range(int(input())):
    n = int(input())
    db = decimalToBinary(n)
    k = len(db)
    temp = []
    for i in str(db):
        if(i!='0'):
            temp.append(int(i)*(3**(k-1)))
        
        k -=1
    print(len(temp))
    temp = reversed(temp)
    for i in temp:
        print(i,end=' ')
    print()