def up(arr):
	for index1 in range(len(arr)):
		for index2 in range(index1+1, len(arr)):
			if arr[index1]>=arr[index2]:
				return False
	return True
