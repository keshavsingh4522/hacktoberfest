def empty_promises(arr):
	zeros=arr.count(0)
	arr=[val for val in arr if val!=0]
	for i in range(zeros): arr.append(0)
	return arr
