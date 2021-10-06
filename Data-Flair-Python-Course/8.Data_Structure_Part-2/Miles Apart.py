def distance(a,b):
	assert(len(str(a))==len(str(b)))
	return sum([abs(int(digit1)-int(digit2)) for digit1,digit2 in zip(list(str(a)),list(str(b)))])
