def all_evens(a,b,res=[]):
	for num in range(a,b+1):
		if all([int(digit)%2==0 for digit in [char for char in str(num)]]):
			res.append(num)
	return res
