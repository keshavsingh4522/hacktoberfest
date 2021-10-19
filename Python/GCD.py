# Python Program to find GCD of Two Numbers

a = float(input(" Please Enter the First Value a: "))
b = float(input(" Please Enter the Second Value b: "))

i = 1
while(i <= a and i <= b):
    if(a % i == 0 and b % i == 0):
        gcd = i
    i = i + 1
    
print("\n HCF of {0} and {1} = {2}".format(a, b, gcd))


#function created to calculate GCD optimally
def gcd(a, b):
    if (b==0):
        return a


    else:
        a_new = a%b
        return gcd(b,a_new)


print("GCD is: ",gcd(a,b))