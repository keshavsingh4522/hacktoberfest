from tkinter.ttk import*
from time import strftime
from tkinter import Label, Tk

#======= Configuring window ========
window = Tk()
window.title("Digital Clock")
window.geometry("600x250")
window.configure(bg="darkred")
window.resizable(False, False)

clock_label = Label(window, bg="dark red", fg="white", font = ("Times", 100, 'bold'), relief='flat')
clock_label.place(x = 20, y = 20)

def update_label():
    current_time = strftime('%H: %M: %S')
    clock_label.configure(text = current_time)
    clock_label.after(80, update_label)

update_label()
window.mainloop()
