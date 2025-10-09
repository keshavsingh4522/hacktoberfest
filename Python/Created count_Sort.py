print("counting Sort")
print("Range of input")
n=int(input())
l=[]
print("Total elements:")
t=int(input())
print("input elements:")

for j in range(0,t):
    p=int(input())
    if p>n:
       print("out of bounds")
    else:
        l.append(p) 
print("Unsorted list is:")        
print(l)  
print("Sorted list is:")
l.sort()
print(l)

