for i in range(3):
    for j in range(3):
        print(f'({i},{j})')

numbers = [5, 2, 5, 2, 2]
l = [2, 2, 2, 2, 7, 7]
for y in numbers:
    output = ''
    for count in range(y):
        output += 'x'

    print(output)
print("\n")
for x in l:
    shape = ''
    for a in range(x):
        shape += 'x'
    print(shape)