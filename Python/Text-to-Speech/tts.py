from tkinter import *
from PIL import Image, ImageTk
import tkinter.font as font
import pyttsx3

root=Tk()
root.title("Text to speech")
root.geometry("338x337")
root.resizable(width=False, height=False)
root.configure(background="black")

engine=pyttsx3.init()
### background image
imag = Image.open("sqpy.png")
render = ImageTk.PhotoImage(imag)
img = Label(image=render,background='black')
img.image = render
img.image = render
img.place(x=0, y=0, relwidth=1, relheight=1)

#entry 
e1=Entry(root,width=40,bd=3,bg='white',fg='black')
e1.place(x=45,y=150)

#button
def gettext():
	global inptxt
	global engine
	inptxt=e1.get()
	engine.say(inptxt)
	engine.runAndWait()
	e1.delete(0,END)
b1=Button(root,text='Listen',command=gettext,bg='black',bd=3,fg='turquoise2',activebackground='black',activeforeground='white')
b1.place(x=150,y=185)

#volume button
def changevolume():
	s=''
	s=vspin.get()
	vspin.delete(0,END)
	if len(s)>0:
		ss=int(s)
		engine.setProperty('volume',float(ss/100))
vspin=Spinbox(root,bg='black',fg='turquoise2',width=7,from_=0,to=100)
vspin.place(x=2,y=290)
bv=Button(root,text='Set volume',command=changevolume,bg='black',fg='turquoise2',activeforeground='white',activebackground='black')
bv.place(x=2,y=310)

#rate button
def changerate():
	s=''
	s=rspin.get()
	rspin.delete(0,END)
	if len(s)>0:
		engine.setProperty('rate',int(s))
rspin=Spinbox(root,bg='black',fg='turquoise2',width=6,from_=1,to=1000)
rspin.place(x=283,y=290)
br=Button(root,text='Set Rate',command=changerate,bg='black',fg='turquoise2',activeforeground='white',activebackground='black')
br.place(x=283,y=310)
#mainloop
root.mainloop()
