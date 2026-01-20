
# Python3 Program to demonstrate
# staircase pattern

# function definition
def pattern(n):

	# for loop for rows
	for i in range(1,n+1):

		# conditional operator
		k =i + 1 if(i % 2 != 0) else i

		# for loop for printing spaces
		for g in range(k,n):
			if g>=k:
				print(end=" ")

		# according to value of k carry
		# out further operation
		for j in range(0,k):
			if j == k - 1:
				print(" * ")
			else:
				print(" * ", end = " ")


# Driver code
n = 10
pattern(n)
