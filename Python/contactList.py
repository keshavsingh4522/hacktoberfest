# contact list code using python tkinter

from Tkinter import *
from tkMessageBox import *
import sqlite3
import ttk
def insert():	
        n=name.get()
        
        p=phone.get()
        m=mail.get()
        if(n!="" and p!="" and  m!="" ):
                con = sqlite3.connect('data.db')
                c = con.cursor()
 
                c.execute('CREATE TABLE IF NOT EXISTS contact (name TEXT, phone TEXT, mail TEXT)')
    
                r=c.execute("INSERT INTO contact(name, phone, mail) VALUES(?,?,?)",(n,p,m))
        
                con.commit()
                if(r):
                         g=showinfo('Insert', 'Successfully inserted')
                        
                         						 
else:
showerror("Error ", "Something went worng check once")

con.close()
        else:
             showerror("Invaild Data ", "Some fields are empty check once!!!")

            
def dele():
    n=name.get()
    if(n!=""):
        con = sqlite3.connect('data.db')
        c = con.cursor()
 
 
        r=c.execute("DELETE FROM contact WHERE name=?",(n,))
        
        con.commit()
        if(r):
             showinfo('Deleted', 'Successfully Deleted')
             n=""
        else:
            showerror("Invaild Data ", "Some error occured check once!!!")

    con.close()
    else:
        showwarning('NO', 'Check filed once!!!!')
        
    
def delete():
    top = Toplevel()
    top.title("DELETE DATA")
    l=Label(top,text="Enter the name to delete")
    l.grid(row=0,columnspan=4)
    e=Entry(top,width=30,textvar=name)
    e.grid(row=2,columnspan=2)
    b=Button(top,text="Delete",command=dele)
    b.grid(row=4,columnspan=4)

    top.mainloop()
def add():
    top = Toplevel()
    top.title("ADD DATA")
    
    lbl_text = Label(top)
    lbl_text.grid(row=0, columnspan=3)
    l=Label(top,text="NAME :-")
    l.grid(row=1)
    l2=Label(top,text="MOBILE :-")
    l2.grid(row=2)
    l3=Label(top,text="E-MAIL :-")
    l3.grid(row=3)
    e=Entry(top,width=30,textvar=name)
    e.grid(row=1,column=1)
    
    e1=Entry(top,width=30,textvar=phone)
    e1.grid(row=2,column=1)

    e2=Entry(top,width=30,textvar=mail)
    e2.grid(row=3,column=1)
    b=Button(top,text="Submit",command=insert)
    b.grid(row=4,columnspan=2)
    
    top.mainloop()
def update():
    showinfo('sorry','These feature not avaiible')

root=Tk()
root.title("Contact Application with Sqlite")
root.geometry("700x500")
name=StringVar()
phone=StringVar()
mail=StringVar()
top=""
f=Frame(root,height=50)

f.pack(fill=X,side=TOP)
l=Label(f,text="Contact Application",bg="white",fg="red")
l.pack(fill=X)
f2=Frame(root,height=100,bg="black")
f2.pack(fill=X,side=TOP)
b1=Button(f2, text="DELETE",command=delete).grid(row=1, column=3, sticky=N,padx=80)
b2=Button(f2, text="+ADD",command=add).grid(row=1, column=4, sticky=N,padx=50)
b3=Button(f2, text="UPDATE",command=update).grid(row=1, column=5, sticky=N,padx=100)
f3=Frame(root,height=200,bg="blue")
f3.pack(fill=X)

tree =ttk.Treeview(f3)


tree["columns"]=("one","two","three")
tree.column("#0", width=210, minwidth=270, stretch=NO)
tree.column("one", width=210, minwidth=200, stretch=NO)
tree.column("two", width=250, minwidth=230,stretch=NO)

tree.heading("#0",text="Name",anchor=W)
tree.heading("one", text="Mobile Number",anchor=W)
tree.heading("two", text="Mail Id",anchor=W)
con = sqlite3.connect('data.db')
c = con.cursor()
c.execute('CREATE TABLE IF NOT EXISTS contact (name TEXT, phone TEXT, mail TEXT)')
r=c.execute("SELECT * FROM contact")
for row in r:
        tree.insert('', 'end',text=row[0],
                         values=(row[1],row[2]))
con.close()

tree.pack(side=TOP,fill=X)
root.resizable(0,0)
root.mainloop()
