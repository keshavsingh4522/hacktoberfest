from main import *
from core.MarsInstaBot import *
from modules.SlowNet import *
import random
import time
username,password=GetLoginfo()

Bot = MarsInstaBot(username,password)
Bot.signIn()

Bot.getUserFollowing('marsian83')
