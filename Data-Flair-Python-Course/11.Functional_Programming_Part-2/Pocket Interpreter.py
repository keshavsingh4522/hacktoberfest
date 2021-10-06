def interpreter():
    print('>>> ',end='')
    expression=input()
    if expression=='bye': return
    print(eval(expression))
    interpreter()

