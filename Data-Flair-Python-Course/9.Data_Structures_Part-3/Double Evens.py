def double_evens(string):
	return any(filter(lambda letter:string[1::2].count(letter)>1,string[1::2]))
