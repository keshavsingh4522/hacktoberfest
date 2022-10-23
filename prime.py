# Program to check if a number is prime or not

n = 31

# To take input from the user
#n = int(input("Enter a number: "))

# define a flag variable
flag = False

# prime numbers are greater than 1
if n > 1:
    # check for factors
    for i in range(2, n):
        if (n % i) == 0:
            # if factor is found, set flag to True
            flag = True
            # break out of loop
            break

# check if flag is True
if flag:
    print(n, "is not a prime number")
else:
    print(n, "is a prime number")
