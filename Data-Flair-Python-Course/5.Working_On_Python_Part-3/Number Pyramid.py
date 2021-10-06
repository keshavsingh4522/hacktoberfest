def num_pyramid(n):
	num=1
	for rows in range(n):
		for row in range(rows+1):
			print(num, end=' ')
			num+=1
		print()
