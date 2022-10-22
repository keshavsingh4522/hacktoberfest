import pyautogui as pg
import time
time.sleep(10)
for i in range(96):
    pg.write("@")
    pg.press("down")
    pg.press("enter")    