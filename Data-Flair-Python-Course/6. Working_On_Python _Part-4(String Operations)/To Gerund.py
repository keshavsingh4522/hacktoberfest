def to_gerund(verb):
	if verb[-1]=='e':
		return f'{verb} becomes {verb[:-1]+"ing"}'
	if verb[-3:]!='ing':
		return f'{verb} becomes {verb+"ing"}'
	return verb
