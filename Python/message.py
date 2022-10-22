import random
import pyautogui as pg
import time

x=('Aryan','Shikhar','Friends','Bros','Shreyansh','Tanmay')
time.sleep(7)
for i in range(2):
    a=random.choice(x)
    pg.write(x)
    pg.press("enter")
    