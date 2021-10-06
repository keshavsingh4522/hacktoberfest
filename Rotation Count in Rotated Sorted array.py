# Python3 program to find number
# of rotations in a sorted and
# rotated array.

def countRotations(arr, n):

	min = arr[0]
	for i in range(0, n):
	
		if (min > arr[i]):
		
			min = arr[i]
			min_index = i
		
	return min_index;

arr = [15, 18, 2, 3, 6, 12]
n = len(arr)
print(countRotations(arr, n))


