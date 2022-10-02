def fibo(n):
    n1, n2 = 0, 1
    count = 0
    
    if n <= 0:
       print("Please enter a positive integer")
    elif n == 1:
       print("Fibonacci sequence :")
       print(n1)
    else:
       print("Fibonacci sequence:")
       while count < n:
           print(n1)
           nth = n1 + n2
           n1 = n2
           n2 = nth
           count += 1
           
n = int(input("Enter the number upto which you want to find the fibonacci series "))
fibo(n)
