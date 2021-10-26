l,u,o,e=[],[],[],[]
for i in sorted(input()):
    if i.isalpha():
        x = u if i.isupper() else l
    else:
        x = o if int(i)%2 else e
    x.append(i)
print("".join(l+u+o+e))

