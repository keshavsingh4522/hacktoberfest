# Find the index of the element in the array such that the sum of all the elements left to the index is equal to the sum of all the elements right to the index.
print("enter list elements: ")
sample = list(map(int, input().split()))
 
sumi = 0
 
sum_left=[]
for val in sample:
    sumi += val
    sum_left.append(sumi)
     
sum_right=[]
for val in sample:
    sum_right.append(sumi)
    sumi -= val

k=len(sum_left)
for i in range(k):
    if sum_left[i] == sum_right[i]:
        print(f"Matching index is {i}.")
        break