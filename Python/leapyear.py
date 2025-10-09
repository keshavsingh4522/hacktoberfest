y=int(input())
if (y%100==0 and y%400==0) or y%4==0: 
    print("leap year")
else: 
    print("not a leap year")