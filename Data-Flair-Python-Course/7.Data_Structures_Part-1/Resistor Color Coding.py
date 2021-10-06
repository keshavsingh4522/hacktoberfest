color_codes=['black','brown','red','orange','yellow','green','blue','violet','grey','white']
def calc_resistance(digit1,digit2,multiplier):
	return str((color_codes.index(digit1)*10+color_codes.index(digit2))*10**color_codes.index(multiplier))+' Ohms'
