def doubles(n):
    num=3
    for index in range(n):
        num=eval(bin(num))<<1
        print(num)

