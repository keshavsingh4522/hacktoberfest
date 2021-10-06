def get_height(height):
	feet=height/30.48
	inches=(feet%1)*12
	print(f'You are {int(feet)}\' {round(inches,1)}" tall.')
