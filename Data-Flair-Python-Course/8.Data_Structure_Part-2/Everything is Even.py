def even_evens(start,end):
	evens=[]
	for num in range(start,end+1):
		if all(map(lambda x:x%2==0,[int(digit) for digit in str(num)])): evens.append(num)
	return evens
