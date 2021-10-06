def money_maker(amount):
	amount=str(amount)
	if len(amount)<4: return amount
	s='';count=0
	for index in range(len(amount)-1,-1,-1):
		count+=1; s+=amount[index];
		if count%3==0 and index!=0: s+=',';
	return s[::-1]
