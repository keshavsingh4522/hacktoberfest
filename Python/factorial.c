n = input("Enter a number: ")
factorial = 1
if int(n) >= 1:
for i in range (1,int(n)+1):
   factorial = factorial * i
print("Factorail of ",n , " is : ",factorial)
