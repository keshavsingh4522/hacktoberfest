def josephus(n, k):
    if (n == 1):
        return 1
    else:
        return (josephus(n - 1, k) + k-1) % n+1


# Driver Program

n = 7
k = 3

print("The chosen place is ", josephus(n, k))