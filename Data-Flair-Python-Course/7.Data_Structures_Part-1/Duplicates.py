list,dups=input('Enter numbers separated by comma').split(','),[]
for num in list:
	if list.count(num)>1: dups.append(num)

for num in set(dups): print(num)
