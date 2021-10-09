#rotating list elements anticlockwise
def rotate(arr,n,k):
    k = k%n
    for i in range(0,n):
        if i < k:
            print(arr[n+i-k] , end=" ")
        else :
            print(arr[i-k], end = " ")
lst = []
n = int(input("enter length of list: "))
for i in range(0,n):
    x = int(input("enter vals of list:"))
    lst.append(x)
print("original list:",lst)
k = int(input("enter how many time to rotate?"))
rotate(lst,n,k)
