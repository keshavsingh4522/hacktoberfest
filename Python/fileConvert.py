file = input("Enter the input file name: ")
output = input("Enter the output file name: ")

f = open(file, 'r')
b = open(output, 'w')

for line in f:
    b.write(line)

f.close()
b.close()
