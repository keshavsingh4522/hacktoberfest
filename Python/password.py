#password generator
import random
letter=[]
for i in range(65,91):
    letter.append(chr(i))
for i in range(97,123):
    letter.append(chr(i))
number=["0","1","2","3","4","5","6","7","8","9"]
char=["~","!","@","#","$","%","^","&","*"]
a=int(input("Enter the number of letters\n"))
b=int(input("Enter the number of number\n"))
c=int(input("Enter the number of character\n"))
passw=""
for i in range(0,a+1):
    passw=passw+random.choice(letter)
for i in range(0,b+1):
    passw +=random.choice(number)
for i in range(0,c+1):
    passw += random.choice(char)
o=list(passw)
random.shuffle(o)
password=""
for i in o:
    password+=i
print(password)
