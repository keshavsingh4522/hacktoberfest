def pangram(sent):
	for letter in 'abcdefghijklmnopqrstuvwxyz':
		if letter not in sent.lower():
			return False
	return True
