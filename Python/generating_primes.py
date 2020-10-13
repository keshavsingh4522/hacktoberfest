# Generation of the primes using seives theorem
# Time complexity: O(n*log(log(n)))
from math import sqrt

def prime_generator(n):
    # we are creating a list to push those numbers
    # Note: we are creating a list as to have less space complexity 
    primes = [True]*(n+1)
    primes[0] = False
    primes[1] =  False
    # As 0 and 1 are Not Primes
    for p in range(2, int(sqrt(n))+1):
        # As the primes starts with 2 
        if primes[p] == True:
            for i in range(p*p, n+1, p):
                #all numbers greater than sqr of 2 and divisible by 2 aren't primes
                primes[i] = False
    # Inserted of the numbers of  the list are displayed 
    for i in range(0, len(primes)):
        if primes[i] == True:
            # we are extracting every number from list and printing them indivudually
            print(i, end=" ")

print("Enter the test cases: ")
t = int(input())
while t:
    print("Enter the highest possibility number: ")
    n = int(input())
    print("The prime numbers upto "+str(n)+" are: \n")
    prime_generator(n)
    t -= 1
        
