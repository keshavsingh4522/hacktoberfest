# Find the index of the element in the array such that the sum of all the elements left to the index is equal to the sum of all the elements right to the index.
print("enter list elements: ")
sample = list(map(int, input().split()))
 
sum = 0
 
sum_left=[]
for val in sample:
    sum += val
    sum_left.append(sum)
     
sum_right=[]
for val in sample:
    sum_right.append(sum)
    sum -= val
 
for i in range(len(sum_left)):
    if sum_left[i] == sum_right[i]:
        print(f"Matching index is {i}.")
        break