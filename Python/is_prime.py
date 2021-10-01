# Is n a prime number?
# A prime number is an integer that can only be divided by 1 and itself.

def isPrime(n):
    n_factors = 0
    for i in range(1, n + 1):
        if n % i == 0:
            n_factors += 1

    if n_factors == 2:
        print("True")
    else:
        print("False")

n = int(input("n: "))

isPrime(n)