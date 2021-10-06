def expanded(num):
	num=str(num)
	return '+'.join([num[index]+'0'*(len(num)-1-index) for index in range(len(num)) if num[index]!='0'])
