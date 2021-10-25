import random
import string
n = int(input())
characters = list(string.ascii_letters + string.digits + "!@#$%^&*()")
s = []

for i in range(0, n):
    c = random.choice(characters)
    s.append(c)

password = ''.join(s)
print(password)
