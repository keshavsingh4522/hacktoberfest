def SumofGP(a,r,n):
    sum = 0
    for i in range(0,n):
        sum += a * (r**i)
    return sum

def ProductofGP(a,r,n):
    prod = 1
    for i in range(0,n):
        prod = prod * a
        a = a * r
    return prod

        



#Main
a = int(input("Enter first term a: "))
r = float(input("Enter common ratio r: "))
n = int(input("Enter number of terms: "))
print("Sum of GP: " + "%.5f"%SumofGP(a,r,n))
print("Product of GP: " + "%.5f"%ProductofGP(a,r,n))
