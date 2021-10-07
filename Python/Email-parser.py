email = input("Enter an email address: ")
at = email.find('@')
username = email[0:at]
domain = email[at+1:]
print("Username is:", username)
print("Domain is:", domain)
