def combat(num1,num2):
	nums=(num1,num2)
	while(num1*num2>0):
		diff=abs(num1-num2)
		if num1>num2:
			print(num1,"is greater than",num2)
			num1=num1-diff-1
		else: print(num1,"is smaller than",num2);num2=num2-diff-1
	return nums[1] if num2>num1 else nums[0]
