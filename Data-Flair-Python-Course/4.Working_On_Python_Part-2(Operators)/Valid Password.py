def valid_password(password):
	p=list(password)
	if len(password)<6 or len(password)>12: return False
	if not(any(i.isdigit() for i in p)): return False
	if not(any(i in '$#@' for i in p)): return False
	if not(any(i.isalpha() for i in p)): return False
	return True
