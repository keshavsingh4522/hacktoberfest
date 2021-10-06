def to_decimal(binary):
	decimal,mul=0,len(str(binary))-1
	for digit in str(binary):
		decimal+=int(digit)*2**mul
		mul-=1
	return decimal
