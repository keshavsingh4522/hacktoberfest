import math
def next_perfect_square(num):
	return (int(math.sqrt(num))+1)**2 if math.sqrt(num)%1==0 else "Not a perfect square itself"
