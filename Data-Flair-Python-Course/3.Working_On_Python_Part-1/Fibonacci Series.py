def fib(length):
	a,b,count=0,1,0
	while(count<length):
		print(a, end=', ');
		count+=1;
		a,b=b,a+b
	print('...')
