def same_subs(sentence):
	count=0
	for word in sentence.split(' '):
		if (word[0]+word[-1]).lower()==(sentence[0]+sentence[-1]).lower():
			count+=1
	return count
