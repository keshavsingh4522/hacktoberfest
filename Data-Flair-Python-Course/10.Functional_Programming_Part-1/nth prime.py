def is_prime(n):
	if n==1: return False
	for num in range(2,int(n/2)+1):
		if n%num==0: return False
	return True

def next_prime(n):
	num=n+1
	while num>n:
		if is_prime(num): return num
		num+=1

def nth_prime(n):
	count,p=0,2
	while count<n-1: p=next_prime(p); count+=1
	return p
