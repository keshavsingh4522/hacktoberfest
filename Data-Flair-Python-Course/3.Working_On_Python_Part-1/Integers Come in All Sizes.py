def size(n):
	count=0
	while(n>1):
		count+=1
		n/=10
	return count
