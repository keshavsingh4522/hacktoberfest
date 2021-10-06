def even_caps(sentence):
	s=''
	for char in sentence:
		if char.isalpha() and ord(char)!=32:
			if char.islower() and ord(char)%2==0:
				s+=chr(ord(char)-32)
			elif char.isupper() and ord(char)%2!=0:
				s+=chr(ord(char)+32)
			else: s+=char
		else: s+=char
	return s
