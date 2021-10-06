from itertools import count
def quarters():
    evens=count(start=0.25,step=0.25)
    return list(next(evens) for _ in range(8))
