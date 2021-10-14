'''                    -------------------------
                    Password Generator using python
                       -------------------------
'''

import random
import array

# User can take any length of password as needed
MAX_LEN = int(input("Enter Password Length(minimum 5) : "))

lower_char = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
					'i', 'j', 'k', 'm', 'n', 'o', 'p', 'q',
					'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
					'z']
upper_char = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
					'I', 'J', 'K', 'M', 'N', 'O', 'p', 'Q',
					'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
					'Z']

digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

SYMBOLS = ['@', '#', '$', '%', '=', ':', '?', '.', '/', '|', '~', '>',
		'*', '(', ')', '<']

# combines all the character arrays above to form one array
COMBINED_LIST = digits + upper_char + lower_char + SYMBOLS

# randomly select at least one character from each character set above
rand_digit = random.choice(digits)
rand_upper = random.choice(upper_char)
rand_lower = random.choice(lower_char)
rand_symbol = random.choice(SYMBOLS)

# combine the character randomly selected above at this stage, the password contains only 4 characters but we want a 12-character password
temp_pass = rand_digit + rand_upper + rand_lower + rand_symbol

for x in range(MAX_LEN - 4):
	temp_pass = temp_pass + random.choice(COMBINED_LIST)

	# convert temporary password into array and shuffle to
	# prevent it from having a consistent pattern
	# where the beginning of the password is predictable
	temp_pass_list = array.array('u', temp_pass)
	random.shuffle(temp_pass_list)

password = ""
for x in temp_pass_list:
		password = password + x
		
# print out password of user length
print(password)
