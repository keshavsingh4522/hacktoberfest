# Find duplicates in an array

def findDup(liArr):
    liArr.sort()
     
    liDuplicate=[]
    for i in range(0, len(liArr)-1):
        if liArr[i]==liArr[i+1]:
            liDuplicate.append(liArr[i])
 
    return liDuplicate
 
print("enter array elements: ")
sample = list(map(int, input().split()))
print(findDup(sample))
#print(findDup([2, 3, 1, 0, 2, 5,3]))