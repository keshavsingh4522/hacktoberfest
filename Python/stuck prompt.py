import pyautogui as p

while True:
    a = p.confirm('Some problems detected \n Shut down computer ?',buttons=['Yes','No'])
    if a=='Yes':
        break