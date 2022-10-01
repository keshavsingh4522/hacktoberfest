from main import *
from core.MarsInstaBot import *
from modules.SlowNet import *
import random
import time
username,password=GetLoginfo()
print('Logging in with username : '+username)
print('Using the password : '+password)
input('Press [ENTER] to confirm\n')
quick_PopRep(username,password,3)
