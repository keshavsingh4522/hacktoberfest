a,b = input("Enter two numbers with space between them no. shouldn't be negative, zero or one\n").split()
a,b = int(a),int(b)

def factors(n):
	l = list()
	for i in (2,int(n**(1/2))+1):
		if n%i == 0:
			l.append(i)
			l.append(n/i)
	return l
if not(a>1 and b>1):
    	print("Kindy enter numbers greater than 1")
f1,f2 = factors(a),factors(b)
for i in f1:
	if i in f2:
		print("Numbers aren't relatively prime")
		break
else:
	print("Numbers are relatively prime")