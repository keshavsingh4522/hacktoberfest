def dividing_reverse(lst):
    for i in range(len(lst)):
        rev = 0
        while lst[i] > 0:
            rev = (rev * 10) + lst[i] % 10
            lst[i] //= 10
        lst[i] = rev
    return lst
print(dividing_reverse(inpList[:]))
