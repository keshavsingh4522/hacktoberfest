def decor(func):
	def wrap(num):
		return '+91 '+num[-10:-5]+' '+num[-5:]
	return wrap

@decor
def phone(num):
	return num
