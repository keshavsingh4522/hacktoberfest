x=int(input())
arr=[]
res=[]

def split(word):
    return [char for char in word]

for i in range(x):
    b=[]
    c=[]
    arr.append(str(input()))
    y=len(arr[i])
    p=int(len(arr[i]) /2)
    
    if(y%2!=0):
        b.append(split(arr[i][p+1:]))
        c.append(split(arr[i][:p]))
         
    else:
        b.append(split(arr[i][p:]))
        c.append(split(arr[i][:p]))
    d = c[0].copy()
    e = b[0].copy()
    for j in range(len(d)):
        if d[j] in b[0]:
            m = d[j]
            c[0].remove(m)
            b[0].remove(m)
    if(len(b[0])==0 and len(c[0])==0):
        res.append('YES')
    else:
        res.append('NO')
for k in range(x):
    print(res[k])