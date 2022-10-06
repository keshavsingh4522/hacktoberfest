import random, string
from tkinter import *
import pyperclip
 
 
#Initialize Window
 
root =Tk()
root.geometry("400x400") #size of the window by default
 
#title of our window
root.title("Random Password Generator")
 
# -------------------  Random Password generator functio
 
output_pass = StringVar()
 
all_combi = [string.punctuation, string.ascii_uppercase, string.digits, string.ascii_lowercase]  #list of all possible characters
 
def randPassGen():
    password = "" # to store password
    for y in range(pass_len.get()):
        char_type = random.choice(all_combi)   #to randomize the occurance of alphabet, digit or symbol
        password = password + random.choice(char_type)
     
    output_pass.set(password)
 
# ----------- Copy to clipboard function
 
def copyPass():
    pyperclip.copy(output_pass.get())
 
#-----------------------Front-end Designing (GUI)
 
pass_head = Label(root, text = 'Password Length', font = 'arial 12 bold').pack(pady=10) #to generate label heading
 
pass_len = IntVar() #integer variable to store the input of length of the password wanted
length = Spinbox(root, from_ = 1, to_ = 132 , textvariable = pass_len , width = 28, font='arial 18').pack()
 
#Generate password button
 
Button(root, command = randPassGen, text = "Generate Password", font="Arial 10", bg='lightblue', fg='black', activebackground="teal", padx=5, pady=5 ).pack(pady= 20)
 
pass_label = Label(root, text = 'Random Generated Password', font = 'arial 12 bold').pack(pady="30 10")
Entry(root , textvariable = output_pass, width = 24, font='arial 16').pack()
 
#Copy to clipboard button
 
Button(root, text = 'Copy to Clipboard', command = copyPass, font="Arial 10", bg='lightblue', fg='black', activebackground="teal", padx=5, pady=5 ).pack(pady= 20)
 
root.mainloop()  #to bundle pack the code for tkinter
