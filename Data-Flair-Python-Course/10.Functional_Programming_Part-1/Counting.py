def count(n=1):
	print(n)
	if n<100: return count(n+1)

count()
