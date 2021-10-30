"""
Calculate nth Fibonacci term where
for n=0 it prints 0, n=1 it prints 1
"""


class NegativeNumber(Exception):
    pass


def fibonacci_iter(n):
    """Iterative implementation of Fibonacci"""
    a, b = 0, 1

    if n < 0:
        raise NegativeNumber("Fibonacci not defined for negative numbers!")

    if n == 0:
        return 0

    for x in range(1, n):
        print("asasda")
        a, b = b, a + b

    return b




if __name__ == "__main__":

    n= int(input("Enter n "))
    print(fibonacci_iter(n))
