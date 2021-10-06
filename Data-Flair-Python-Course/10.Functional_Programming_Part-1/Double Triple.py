def double_triple(mylist):
	return list(map(lambda x:x*2 if x%2==0 else x*3,mylist))
