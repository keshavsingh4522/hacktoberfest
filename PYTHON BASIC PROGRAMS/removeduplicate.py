numbers = [1,2,3,4,3,21,1,2,3,43]
print(numbers)
for i in numbers:
    n = numbers.count(i)
    if n>=2 :
        numbers.remove(i)
print(numbers)

#by mosh
uniques = []
for number in numbers:
    if number not in uniques:
        uniques.append(number)
print(uniques)

