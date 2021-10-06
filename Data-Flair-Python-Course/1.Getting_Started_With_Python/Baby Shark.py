def print_doo():
	return ' doo'*6

def baby_shark():
	sharks=['Baby','Mommy','Daddy','Grandma','Grandpa']
	for shark in sharks:
		for index in range(3): print(shark+' shark,%s' %(print_doo()))
		print(shark+' shark!\n')
	for index in range(3):
		print('Let\'s go hunt,%s' %(print_doo()))
	print('Let\'s go hunt!\n\nRun away..')

baby_shark()
