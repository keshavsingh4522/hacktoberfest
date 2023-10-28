num=int(input("Enter a number"))
sum=0
while num!=0:
    remainder=num%10
    sqrofdigits=remainder**2
    sum=sum+sqrofdigits
    num=int(num/10)

print("sum of square of digits of given number is:",sum)
