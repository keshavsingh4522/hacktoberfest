from functools import reduce
def add_all(num):
    return reduce(lambda a,b:a+b,range(num+1))
    #or return sum(range(1,num+1))
