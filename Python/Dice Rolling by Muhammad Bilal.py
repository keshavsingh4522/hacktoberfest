#Developer : Muhammad Bilal (Muhammad-Bilal-MB)

from tkinter import *
from tkinter import messagebox
import random

def Roll():
    a = a1.get()
    b = a2.get()
    c = int(a3.get())
    d = int(a4.get())
    e = a5.get()
    diceNumber = random.randint(1,6)
    if c == d:

        messagebox.showinfo("Error","Error !")
        
    elif c == diceNumber:

        messagebox.showinfo("Dice Rolled",diceNumber)
        messagebox.showinfo("Hoohoo!",a+" WON :-)")
        messagebox.showinfo("Dare",b+" "+e)
        
    elif d == diceNumber:

        messagebox.showinfo("Dice Rolled",+diceNumber)
        messagebox.showinfo("Hoohoo!",b+" WON :-)")
        messagebox.showinfo("Dare",a+" "+e)
    elif (c and d == diceNumber):

        messagebox.showinfo("Tie","Its a tie")
    else:

        messagebox.showinfo("Dice Rolled",diceNumber)
        messagebox.showinfo("Try Again!","Not a Selected Number , Please Roll Again")
        
    
root = Tk()
root.title("Dice Rolling Simulator")
root.configure(background = "orange")
label1=Label(root,text="Welcome to Dice Rolling Simulator,Let's Play",bg="red",fg="white",borderwidth=10,relief="groove",font = "broadway 30 bold").grid(row=0,column=0,sticky=W)
label2=Label(root,text="Enter Player 1 name :",bg="orange",fg="white",font="forte 23").grid(row=1,column=0,sticky=W)
a1 = StringVar()
textentry1 = Entry(root,width=20,bg="white",textvariable=a1,font="stencil",borderwidth=7).grid(row=1,column=0,padx=5,pady=10,ipady=5,sticky=E)
label3=Label(root,text="Enter Player 2 name :",bg="orange",fg="white",font="forte 23").grid(row=2,column=0,sticky=W)
a2 = StringVar()
textentry2 = Entry(root,width=20,bg="white",textvariable=a2,font="stencil",borderwidth=7).grid(row=2,column=0,padx=5,pady=10,ipady=5,sticky=E)
label4=Label(root,text="Player 1 Choose your number between 1-6",bg="orange",fg="white",font="forte 23").grid(row=3,column=0,sticky=W)
a3 = StringVar()
textentry3 = Entry(root,width=10,bg="white",textvariable=a3,font="stencil",borderwidth=7).grid(row=3,column=0,padx=5,pady=10,ipady=5,sticky=E)
label5=Label(root,text="Player 2 Choose your number between 1-6",bg="orange",fg="white",font="forte 23").grid(row=4,column=0,sticky=W)
a4 = StringVar()
textentry4 = Entry(root,width=10,bg="white",textvariable=a4,font="stencil",borderwidth=7).grid(row=4,column=0,padx=5,pady=10,ipady=5,sticky=E)
label6=Label(root,text="What does the loser have to do? (Dare)",bg="orange",fg="blue",font="forte 23").grid(row=5,column=0,sticky=W)
a5 = StringVar()
textentry5 = Entry(root,width=60,bg="white",textvariable=a5,font="stencil",borderwidth=7).grid(row=6,column=0,padx=5,pady=10,ipady=5,sticky=W)
button1 = Button(root,text="Roll",width=15,bg="silver",fg="dark green",font="impact 12",command=Roll).grid(row=7,column=0,padx=10,pady=25,ipady=10,ipadx=25,sticky=W)
button2 = Button(root,text="Cancel",width=15,bg="silver",fg="red",font="impact 12",command=root.destroy).grid(row=7,column=0,padx=10,pady=25,ipady=10,ipadx=25,sticky=E)
root.mainloop()
