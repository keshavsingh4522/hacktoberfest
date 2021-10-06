def remove_vowels(string):
	s=''
	for letter in string:
		if letter not in ['a','e','i','o','u']: s+=letter;
	return s
