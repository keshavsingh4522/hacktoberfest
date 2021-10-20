import math
import numpy
from fractions import Fraction

sin_answers = ['sin', 'sine', 's', 'Sine', 'Sin']
cos_answers = ['cos', 'cosine', 'c', 'Cosine']
tan_answers = ['tan', 'tangent', 't', 'Tangent']

# Get input from user
loop = True
while loop:
	user = input('What trigonometric function do you need help with (Sin, Cosine, Tangent)? ')
	if user in sin_answers:
		break	
	elif user in cos_answers:
		break
	elif user in tan_answers:				#Loop will only break if the user's answers was part of the answers in the lists above
		break
	else:
		print('')
		print('That was not a valid answer. Please try again.')
		print('')
if user in sin_answers:		#These functions are specific to sin only
	loop2 = True
	while loop2:
		try:
				print('')
				user2 = input('Please enter the amount of radians, or type "break" if you want to stop the loop: ')
				sin = math.sin(float(user2))
				print('The sin of ' + str(user2) + ' radians is:' + str(sin) + '\n\nRounded it is: ' + str(round(sin, 4)) + ' radians.\n\nIn degrees, it is: ' + str(math.degrees(sin)) + ' degrees.')

		except ValueError as e: #This error is to handle the user entering anything other than numbers
			print('')
			print('Loop broken! The program will now automatically stop running. Have a nice day!')
			break

		except TypeError as e: #This error is to handle the program mishandling numbers
			print('')
			print('There was an error concacenating the numbers. Please reload the program.')
			break		  
		
		
elif user in cos_answers: #This function is specific to cos only
	loop3 = True
	while loop3:
		try:
				print('')
				user2 = input('Please enter the amount of radians, or type "break" if you want to stop the loop: ')
				cos = math.cos(float(user2))
				print('The cosine of ' + str(user2) + ' radians is: ' + str(cos) + '\n\nRounded it is: ' + str(round(cos, 4)) + ' radians.\n\nIn degrees, it is: ' + str(math.degrees(cos)) + ' degrees.')

		except ValueError as e:
			print('')
			print('Loop broken! The program will now automatically stop running. Have a nice day!')
			break

		except TypeError as e:
			print('')
			print('There was an error concacenating the numbers. Please reload the program.')
			break		  
elif user in tan_answers: #This function is specific to tan only
	loop4 = True
	while loop4:
		try:
				print('')
				user2 = input('Please enter the amount of radians, or type "break" if you want to stop the loop: ')
				tan = math.tan(float(user2))
				print('The tangent of ' + str(user2) + ' radians is: ' + str(tan) + '\n\nRounded it is: ' + str(round(tan, 4)) + ' radians.\n\nIn degrees, it is: ' + str(math.degrees(tan)) + ' degrees.')

		except ValueError as e:
			print('')
			print('Loop broken! The program will now automatically stop running. Have a nice day!')
			break

		except TypeError as e:
			print('')
			print('There was an error concacenating the numbers. Please reload the program.')
			break	
