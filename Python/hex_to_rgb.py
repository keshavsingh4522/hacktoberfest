hex = input("Enter hex code: ").lstrip("#")
if len(hex)!= 6:
	print("Invalid hex code")
else:
	for i in range(0,6,2):
		d = int(hex[i:i+2],16)
		print(d)