def greatest(arr):
	for index1 in range(1,len(arr)):
		if arr[index1]<=sum(arr[:index1]):
			return False
	return True
