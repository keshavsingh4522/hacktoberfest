import numpy as np
from matplotlib import pyplot as plt

def fib(n):
    if n <= 1:
        return n
    else:
        return(fib(n-1)+fib(n-2))


x = [fib(n) for n in range(15)]
y = np.linspace(1, len(x), len(x), dtype=int)

plt.plot(y, x)
plt.title('Fibonacci Sequence')
plt.xlabel('Passed Value')
plt.ylabel('Fibonacci Sequence Value')
plt.show()