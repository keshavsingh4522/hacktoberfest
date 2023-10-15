n=int(input("Enter Number: "))
arr=[]
for i in range(1,n+1):
    arr.append(int(input("Enter Element: ")))
x=0
y=0
for i in arr:
    if(i>x):
        y=x
        x=i
print(x,y)