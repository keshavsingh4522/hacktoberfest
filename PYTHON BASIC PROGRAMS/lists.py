names = ['john', 'bob' , 'mosh', 'shaibaz' , 'rakesh']

names[0] = 'smith'
print(names)

numbers = [ 1,2,3,4,5,66,7,3,22,34,99,543,56,4345,32223,5443]
largest = numbers[0]

for number in numbers:
    if largest < number:
        largest = number
print(largest)