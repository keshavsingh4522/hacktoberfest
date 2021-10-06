def super_isogram(sentence):
	for word in sentence.split(' '):
		for letter in word:
			if word.count(letter.lower())>1:
				return False
	return True
