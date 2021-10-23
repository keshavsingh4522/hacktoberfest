from tkinter import *
from tkcalendar import DateEntry
from PIL import ImageTk, Image
import os
from tkinter import filedialog
from tkinter import messagebox
import pymysql
import re
import mysql.connector
from mysql.connector import Error

connection = pymysql.connect(host="localhost", user="root", password="", database="fatema")
cursor = connection.cursor()
#cursor2 = connection.cursor()

st = "SHOW TABLES LIKE 'fatema3'"
cursor.execute(st)
result = cursor.fetchone()
studentSQL= """CREATE TABLE fatema1(ID BIGINT(20) ,
FIRSTNAME VARCHAR(20) NOT NULL,
LASTNAME VARCHAR(20) NOT NULL,
ADDRESS VARCHAR(50) NOT NULL,
ROLLNO BIGINT(20) NOT NULL,
EMAIL VARCHAR(30) NOT NULL,
DOB VARCHAR(20) NOT NULL,
GENDER VARCHAR(20) NOT NULL,
NUMBER BIGINT(20) NOT NULL,
PHOTO LONGBLOB NOT NULL"""
if not result: cursor.execute(studentSQL)
#connection.commit()

window = Tk()
window.title("FINAL Project")
window.geometry("800x800")
window.config(bg="lightblue") 
def converttobinarydata():
    with open("test.jpg", 'rb') as file:
        binaryData= file.read()
    return binaryData

    
def subdata():
    print("Successful2")
    
    
    si=entsi.get()
    fn=entfn.get()
    ln=entln.get()
    sa=entsa.get()
    rn=entrn.get()
    ei=entei.get()
    dob=entdob.get()
    g=var.get()
    mn=entmn.get()
    valei=False
    valmn=False
    valsi=False
    valfn=False
    valln=False
    valsa=False
    valrn=False
    print("Successful3")
    
    if si=="":
        messagebox.showwarning("Error", "Enter the student id.")
    else:
        valsi=True
    if fn=="":
        messagebox.showwarning("Error", "Enter your first name")
    else:
        valfn=True
    if fn=="":
        messagebox.showwarning("Error", "Enter your last name")
    else:
        valln=True
    if sa=="":
        messagebox.showwarning("Error", "Enter your address")
    else:
        valsa=True    
    if rn=="":
        messagebox.showwarning("Error", "Enter the student roll no.")
    else:
        valrn=True
    if ei=="":
        messagebox.showwarning("Error", "Enter the email id.")
    elif re.search('^\w+@\w+\.com$', ei):
        valei=True
    else:
        messagebox.showwarning("Error", "Invalid email id.")   
    if mn=="":
        messagebox.showwarning("Error", "Enter the mobile no.")
    elif re.search('^[^1(a-z)]\d{9}$', mn):
        valmn=True    
    else:
        messagebox.showwarning("Error", "Invalid number")
    
    

    if valrn==True and valmn==True and valei==True and valsi==True and valfn==True and valln==True and valsa==True:
        sql= "INSERT INTO fatema3(ID,FIRSTNAME,LASTNAME,ADDRESS,ROLLNO,EMAIL,DOB,GENDER,NUMBER,PHOTO) VALUES(%s,%s,%s,%s,%s,%s,%s,%s,%s,%s)"""
        img1= converttobinarydata()
        b=(si,fn,ln,sa,rn,ei,dob,g,mn,img1)
        cursor.execute(sql,b)
        connection.commit()
def open_img():
    x = filedialog.askopenfilename(title='open')
    img = Image.open(x)
    img = img.resize((250, 250), Image.ANTIALIAS)
    tkimg = ImageTk.PhotoImage(img)
    img.save("test.jpg")
    panel = Label(window, image=tkimg)
    panel.image = tkimg
    panel.place(x=350, y=600)
def dispdata():    
    windows = Toplevel(window)
    windows.title("Personal Data")
    windows.geometry("800x800") 
    windows.config(bg="lightblue")

    lsi = Label(windows,text="STUDENT ID",width=20)
    lsi.place(x =50,y=200)
    l0 = Label(windows,width=len(entsi.get()),anchor=W,justify=LEFT)
    l0.place(x =200,y=200)
    l0.config(text=entsi.get())
    
    lfn = Label(windows,text="FIRST NAME:",width=20)
    lfn.place(x =50,y=250)
    l1 = Label(windows,width=len(entfn.get()),anchor=W,justify=LEFT)
    l1.place(x =200,y=250)
    l1.config(text=entfn.get())

    lln = Label(windows,text="LAST NAME:",width=20)
    lln.place(x =50,y=300)
    l2 = Label(windows,width=len(entln.get()),anchor=W,justify=LEFT)
    l2.place(x =200,y=300)
    l2.config(text=entln.get())

    lsa = Label(windows,text="STUDENT ADDRESS:",width=20)
    lsa.place(x =50,y=350)
    l3 = Label(windows,width=len(entsa.get()),anchor=W,justify=LEFT)
    l3.place(x =200,y=350)
    l3.config(text=entsa.get())

    lrn = Label(windows,text="ROLL NO:",width=20)
    lrn.place(x =50,y=400)
    l4 = Label(windows,width=len(entrn.get()),anchor=W,justify=LEFT)
    l4.place(x =200,y=400)
    l4.config(text=entrn.get())

    lei = Label(windows,text="EMAIL:",width=20)
    lei.place(x =50,y=450)
    l5 = Label(windows,width=len(entei.get()),anchor=W,justify=LEFT)
    l5.place(x =200,y=450)
    l5.config(text=entei.get())

    ldob = Label(windows,text="DOB:",width=20)
    ldob.place(x =50,y=500)
    l6 = Label(windows,width=len(entdob.get()),anchor=W,justify=LEFT)
    l6.place(x =200,y=500)
    l6.config(text=entdob.get())

    lg = Label(windows,text="GENDER:",width=20)
    lg.place(x =50,y=550)
    l7 = Label(windows,width=len(var.get()),anchor=W,justify=LEFT)
    l7.place(x =200,y=550)
    l7.config(text=var.get())

    lmn = Label(windows,text="MOBILE NO:",width=20)
    lmn.place(x =50,y=600)
    l8 = Label(windows,width=len(entmn.get()),anchor=W,justify=LEFT)
    l8.place(x =200,y=600)
    l8.config(text=entmn.get())

    pathf="test.jpg"
    im = Image.open(pathf)
    im=im.resize((250,250))
    tkimage = ImageTk.PhotoImage(im)
    panel1 =Label(windows, image=tkimage)
    panel1.image=tkimage
    panel1.place(x=500, y=50)

    windows.mainloop()

labelsi = Label(window,text="STUDENT ID",width=20)
labelsi.place(x =50,y=50)
entsi = Entry(window)
entsi.place(x=200,y=50)

labelfn = Label(window,text="FIRST NAME",width=20)
labelfn.place(x =50,y=100)
entfn = Entry(window)
entfn.place(x=200,y=100)

labelln = Label(window,text="LAST NAME",width=20)
labelln.place(x =50,y=150)
entln = Entry(window)
entln.place(x=200,y=150)

labelsa = Label(window,text="STUDENT ADDRESS",width=20)
labelsa.place(x =50,y=200)
entsa = Entry(window,width=50)
entsa.place(x=200,y=200)

labelrn = Label(window,text="ROLL NUMBER",width=20)
labelrn.place(x =50,y=275)
entrn = Entry(window)
entrn.place(x=200,y=275)

labelei = Label(window,text="EMAIL ID",width=20)
labelei.place(x =50,y=350)
entei = Entry(window)
entei.place(x=200,y=350)

labeldob = Label(window,text="DOB",width=20)
labeldob.place(x =50,y=400)
entdob = DateEntry(window)
entdob.place(x=200,y=400)

labelg = Label(window,text="GENDER",width=20)
labelg.place(x =50,y=450)
list1=["FEMALE","OTHERS"]
var=StringVar()
var.set("MALE")
entg = OptionMenu(window,var,*list1)
entg.place(x=200,y=450)

labelmn = Label(window,text="MOBILE NO.",width=20)
labelmn.place(x =50,y=500)
entmn = Entry(window)
entmn.place(x=200,y=500)

btn = Button(window, text='open image',width=20,command=open_img)
btn.place(x=100,y=550)

btsub = Button(window,text="SUBMIT",width=20, command=subdata)
btsub.place(x=300,y=550)

btdisp= Button(window,text="DISPLAY",width=20, command=dispdata)
btdisp.place(x=500,y=550)

window.mainloop()
