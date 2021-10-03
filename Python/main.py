from tkinter import *
import pyperclip
import random

############ FUNCTION ###############

def generate_color():
    hex_entry.delete(0,END)
    color = "%06x" % random.randint(0, 0xFFFFFF)
    hex_entry.insert(0,color)
    pyperclip.copy(color)
    pyperclip.paste()
    canvas.create_oval(0,0,70,70,outline="black",fill="#"+color,width=2)

    

###########  WINDOW ############
window = Tk()
window_title = window.title("color_generator")
window.minsize(600,400)
window.config(padx=50,pady=50,background="#8236CB")
canvas=Canvas(height=300,width=700,background="#8236CB",highlightthickness=0)
logo = PhotoImage(file="tkinter\color-picker\logo.png")
canvas.create_image(350,157,image=logo)
canvas.grid(row=0,column=1)

############# LABEL ################
color_hex = Label(text="hex_value",background="#8236CB")
color_hex.grid(row=1,column=0)
color_hex.config(font=("Courier",24,"bold"),padx=10)


############# TEXTAREA ###############

hex_entry=Entry(width=20)
hex_entry.grid(row=1,column=1)
hex_entry.config(font=("Courier",24,"bold"))

############# BUTTON ###############

generate= Button(text="Generate",command=generate_color,background="#64cd63")
generate.grid(row=1,column=2)
generate.config(font=("Courier",24,"bold"))




window.mainloop()

