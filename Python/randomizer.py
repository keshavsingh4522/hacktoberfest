
# Python Program to randomizer on a list of items
import random

num = int(input('Enter length of list: '))

items = []
for x in range(num):
    item = input(f'Enter item #{x+1}: ')
    items.append(item)

print(f'The random choice is: {random.choice(items)}')