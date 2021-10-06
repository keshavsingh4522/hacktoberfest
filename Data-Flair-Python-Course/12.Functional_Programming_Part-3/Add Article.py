def decor(func):
	def wrap(word):
		return 'an '+word if word[0] in ['a','e','i','o','u'] else 'a '+word
	return wrap

@decor
def add_article(word):
	return word
