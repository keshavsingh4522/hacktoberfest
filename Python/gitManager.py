#!/usr/bin/python3
import os
from tkinter import *

window=Tk()
window.title('Git Credentials Changer')
window.geometry("500x250")

git_credentials_text="https://github.com:{}@github.com"
git_config_text="""[user]
	email = {}
	name = {}
[credential]
	helper = store"""

homePath=os.path.expanduser('~')

userEmail=StringVar()
userName=StringVar()
personalAccessToken=StringVar()

def saveAccount():
    git_credential=open(homePath+'/.git-credentials','w')
    git_config=open(homePath+'/.gitconfig','w')
    git_credential.write(git_credentials_text.format(personalAccessToken.get()))
    git_config.write(git_config_text.format(userEmail.get(),userName.get()))

Label(window,text='Git user name').pack(anchor=CENTER)
Entry(window,width=40,bd=3,textvariable=userName).pack(anchor=CENTER)

Label(window,text='Git user email').pack(anchor=CENTER)
Entry(window,width=40,bd=3,textvariable=userEmail).pack(anchor=CENTER)

Label(window,text='Personal Access Token').pack(anchor=CENTER)
Entry(window,show='*',width=40,bd=3,textvariable=personalAccessToken).pack(anchor=CENTER)

Button(window,text='Save',command=saveAccount).pack(anchor=CENTER)

window.mainloop()

