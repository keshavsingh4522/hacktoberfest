def parentheses(text):
	groups,group=[],''
	count=0
	for char in text:
		group+=char
		count=count+1 if char=='(' else count-1
		if count==0:
			groups.append(group)
			group=''
	return groups
