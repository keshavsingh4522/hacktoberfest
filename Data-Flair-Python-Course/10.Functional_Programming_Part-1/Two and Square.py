def two_and_square(count,num=-1):
	if count<1: return
	num=(num+2)**2
	print(num); count-=1
	two_and_square(count,num)
