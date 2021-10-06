def bitwise_swap(a,b):
	a^=b
	b^=a
	a^=b
	return a,b
