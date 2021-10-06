def star_diamond():
	for row in range(4):
		for space in range(3-row):
			print(' ',end='')
		for star in range(row+1):
			print('*',end='')
		for star in range(row):
			print('*',end='')
		print()
	for row in range(3):
		for space in range(row+1):
			print(' ',end='')
		for star in range(3-row):
			print('*',end='')
		for star in range(2-row):
			print('*',end='')
		print()

star_diamond()
