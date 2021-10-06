def weird_alliteration(string):
	words=string.split(' ')
	for index in range(len(words)-1):
		if words[index][len(words[index])-1]!=words[index+1][0]: return False
	return True
