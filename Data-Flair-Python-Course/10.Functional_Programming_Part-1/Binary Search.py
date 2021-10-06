def binary(data, v, start, end):
	mid=int((start+end)/2)
	if start>end: return -1
	elif data[mid]==v: return mid
	elif data[mid]>v: return binary(data, v, start, mid-1)
	else: return binary(data, v, mid+1, end)
