def divide(word,size):
	return [word[index:index+size] for index in range(0, len(word), size)]
