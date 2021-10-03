def binomialCoefficient(n, k):
    # Since C(n, k) = C(n, n-k)
    if k > n-k:
        k = n-k
    
    res = 1

    # Calculate [n*(n-1)*.......*(n-k+1)]/[k*(k-1)*.....*1]
    for i in range(k):
        res *= (n - i)
        res //= (i + 1)

    return res
