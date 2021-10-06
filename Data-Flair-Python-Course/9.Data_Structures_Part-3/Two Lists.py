def two_lists(list1,list2):
	temp=list1*2
	temp[::2]=list1
	temp[1::2]=list2
	return temp
