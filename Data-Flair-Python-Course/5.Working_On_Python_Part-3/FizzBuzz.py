def fizzbuzz():
	for num in range(1,101):
		if num%3==0: print("Fizz",end='');
		if num%5==0: print("Buzz"); continue
		if num%3==0: print(); continue
		print(num)

fizzbuzz()
