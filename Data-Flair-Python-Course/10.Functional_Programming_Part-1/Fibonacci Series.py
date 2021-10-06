a,b=0,1
num=int(input("How many?"))
print(0,1,end=' ')
def fibr(num):
    if num==2: return
    global a,b
    a,b=b,a+b
    print(b,end=' ')
    fibr(num-1)

fibr(num)
