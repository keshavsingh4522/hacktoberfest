def ones_complement(bin):
	return ''.join([str((1,0)[int(digit)]) for digit in bin])
