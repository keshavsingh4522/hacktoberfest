def abbreviation(abbs,words):
	for abb in abbs:
		count=0
		for word in words:
			if word.startswith(abb):
				count+=1
		if count!=1: return False
	return True
