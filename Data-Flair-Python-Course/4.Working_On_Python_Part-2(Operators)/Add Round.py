def add_round(a,b):
	return round(a)+round(b)

def round(num):
	return num-(num%10)+10 if num%10>=5 else num-(num%10)
