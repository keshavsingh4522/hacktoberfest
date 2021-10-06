vowels=['a','e','i','o','u']
def add_indefinite_article(noun):
	return 'an '+noun if noun[0] in vowels else 'a '+noun
