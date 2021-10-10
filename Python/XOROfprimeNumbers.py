"""
    XOR of prime numbers in a given range of an array
    Github Username :- @lmas3009
"""

# importing math module to perform square root operation
import math

def XOR_prime(n,arr,Queries):
	xor = 0
	for q in Queries:
		# q[0] = left and q[1] = right
		for i in arr[q[0]-1:q[1]-1]:
			if(i>1):
				for j in range(2,int(math.sqrt(i))+1):
					
					# checking if it is a prime number or not
					if(i%j==0):
						break
				else:
					# if it is a prime number we are applying xor opertation on the number
					xor = xor ^ i
		print(f"The XOR value from the range {q[0]} to {q[1]} in the array {arr} is {xor}")		
		



# length of an array
n = int(input())

# reading the array values
arr = list(map(int,input().split()))

# Number of queries
q = int(input())

# empty list to add all the queries values
Queries = []

"""  reading queries l = left, r = right
staring with index 1 to n """

for _ in range(q):
	l,r = map(int,input().split())
	# appending the l,r values into the Queries list
	Queries.append([l,r])
	
# In XOR_prime function we are passing n = length of array, arr = array, Queries = Queries list
XOR_prime(n,arr,Queries)


""" 
	Test Case 01:
		n = 4
		arr = [1,6,2,7]
		q = 2
		l,r = 1,4
		l,r = 2,3
		
		Output:
			The XOR value from the range 1 to 4 in the array [1, 6, 2, 7] is 2
			The XOR value from the range 2 to 3 in the array [1, 6, 2, 7] is 2
	
	Test Case 02:
		n = 7
		arr = [1,8,7,9,5,3,6]
		q = 4
		l,r = 1,7
		l,r = 1,5
		l,r = 4,7
		l,r = 3,5
		
		Output:
			The XOR value from the range 1 to 7 in the array [1, 8, 7, 9, 5, 2, 3, 6] is 0
			The XOR value from the range 1 to 5 in the array [1, 8, 7, 9, 5, 2, 3, 6] is 7
			The XOR value from the range 4 to 7 in the array [1, 8, 7, 9, 5, 2, 3, 6] is 0
			The XOR value from the range 3 to 5 in the array [1, 8, 7, 9, 5, 2, 3, 6] is 7
	
	
"""
