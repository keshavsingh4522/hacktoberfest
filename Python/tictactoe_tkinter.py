from tkinter import *
from tkinter import messagebox
import sys
global count
root= Tk()
root.configure(bg="black")
root.title("TIC TAC TOE")
Label(text="TIC TAC TOE",fg="white",bd=5,bg="black").grid(row=0,column=0,columnspan=3)
count=0
p1=Label(text="X : player 1 =",bg="black",fg="white").grid(row=1,column=0)
pn1=Entry(root,fg="black",width=15,bd=4)
pn1.grid(row=1,column=1)
p2=Label(text="O : player 2 =",bg="black",fg="white").grid(row=2,column=0)
pn2=Entry(root,fg="black",width=15,bd=4)
pn2.grid(row=2,column=1)

def readname():
	global n1
	global n2	
	n1=pn1.get()
	n2=pn2.get()	
	start()
	st['bg']="yellow"
	st['fg']="black"
	st['text']="game is ready"
	st['state']=DISABLED
st="X"
l=[0,0,0,0,0,0,0,0,0]
def check():
	global l
	global count
	global n1
	global n2
	x=''
	flag=0
	if count>=5:
		if l[1]==l[4] and l[4]==l[7]:
			x=l[1]
			if x=="X":
				messagebox.showinfo("game over",n1+" won the game")
				flag=1
				sys.exit()
			if x=="O":
				messagebox.showinfo("game over",n2+" won the game")
				flag=1
				sys.exit()
		if l[0]==l[1] and l[1]==l[2] or l[0]==l[4] and l[4]==l[8]:
			x=l[0]
			if x=="X":
				messagebox.showinfo("game over",n1+" won the game")
				flag=1
				sys.exit()
			if x=="O":
				messagebox.showinfo("game over",n2+" won the game")
				flag=1
				sys.exit()
		if l[3]==l[4] and l[4]==l[5] or l[0]==l[3] and l[3]==l[6]:
			x=l[3]
			if x=="X":
				messagebox.showinfo("game over",n1+" won the game")
				flag=1
				sys.exit()
			if x=="O":
				messagebox.showinfo("game over",n2+" won the game")
				flag=1
				sys.exit()
		if l[6]==l[7] and l[7]==l[8] or l[2]==l[4] and l[4]==l[6] or l[2]==l[5] and l[5]==l[8] :
			x=l[6]
			if x=="X":
				messagebox.showinfo("game over",n1+" won the game")
				flag=1
				sys.exit()
			if x=="O":
				messagebox.showinfo("game over",n2+" won the game")
				flag=1
				sys.exit()
	if count==9 and flag==0:
		messagebox.showinfo("game over"," GAME TIED ")
		sys.exit()
def click1():
	global count
	global st
	global l
	if count%2==1:
		st="O"
		b1['cursor']="tcross"
	else:
		st="X"
		b1['cursor']="circle"
	b1['text']=st
	b1['state']=DISABLED
	if st=="X":
		b1['bg']="light green"
	if st=="O":
		b1['bg']="light blue"
	l[0]=st
	count+=1
	check()
def click2():
	global count
	global l
	global st
	if count%2==1:
		st="O"
		b2['cursor']="tcross"
	else:
		st="X"	
		b2['cursor']="circle"
	l[1]=st
	b2['text']=st
	b2['state']=DISABLED
	if st=="X":
		b2['bg']="light green"
	if st=="O":
		b2['bg']="light blue"
	count+=1
	check()

def click3():
	global count
	global st
	global l
	if count%2==1:
		st="O"
		b3['cursor']="tcross"
	else:
		st="X"	
		b3['cursor']="circle"
	l[2]=st
	b3['text']=st
	b3['state']=DISABLED
	if st=="X":
		b3['bg']="light green"
	if st=="O":
		b3['bg']="light blue"
	count+=1
	check()

def click4():
	global st
	global count
	global l
	if count%2==1:
		st="O"
		b4['cursor']="tcross"
	else:
		st="X"	
		b4['cursor']="circle"
	l[3]=st
	b4['text']=st
	b4['state']=DISABLED
	if st=="X":
		b4['bg']="light green"
	if st=="O":
		b4['bg']="light blue"
	count+=1
	check()

def click5():
	global st
	global count
	global l
	if count%2==1:
		st="O"
		b5['cursor']="tcross"
	else:
		st="X"	
		b5['cursor']="circle"
	l[4]=st
	b5['text']=st
	b5['state']=DISABLED
	if st=="X":
		b5['bg']="light green"
	if st=="O":
		b5['bg']="light blue"
	count+=1
	check()

def click6():
	global count
	global st
	global l
	if count%2==1:
		st="O"	
		b6['cursor']="tcross"
	else:
		st="X"	
		b6['cursor']="circle"
	l[5]=st
	b6['text']=st
	b6['state']=DISABLED
	if st=="X":
		b6['bg']="light green"
	if st=="O":
		b6['bg']="light blue"
	count+=1
	check()

def click7():
	global count
	global st
	global l
	if count%2==1:
		st="O"	
		b7['cursor']="tcross"
	else:
		st="X"	
		b7['cursor']="circle"
	l[6]=st
	b7['text']=st
	b7['state']=DISABLED
	if st=="X":
		b7['bg']="light green"
	if st=="O":
		b7['bg']="light blue"
	count+=1
	check()

def click8():
	global count
	global st
	global l
	if count%2==1:
		st="O"	
		b8['cursor']="tcross"
	else:
		st="X"	
		b8['cursor']="circle"
	l[7]=st
	b8['text']=st
	b8['state']=DISABLED
	if st=="X":
		b8['bg']="light green"
	if st=="O":
		b8['bg']="light blue"
	count+=1
	check()

def click9():
	global count
	global st
	global l
	if count%2==1:
		st="O"	
		b9['cursor']="tcross"
	else:
		st="X"	
		b9['cursor']="circle"
	l[8]=st
	b9['text']=st
	b9['state']=DISABLED
	if st=="X":
		b9['bg']="light green"
	if st=="O":
		b9['bg']="light blue"
	count+=1
	check()

b1=Button(root,bd=3,width=15,text="",height=6,state=DISABLED,command=click1)
b1.grid(row=4,column=0)
b2=Button(root,bd=3,width=15,text="",height=6,state=DISABLED,command=click2)
b2.grid(row=4,column=1)
b3=Button(root,bd=3,width=15,text="",height=6,command=click3,state=DISABLED)
b3.grid(row=4,column=2)
b4=Button(root,bd=3,width=15,text="",height=6,command=click4,state=DISABLED)
b4.grid(row=5,column=0)
b5=Button(root,bd=3,width=15,text="",height=6,command=click5,state=DISABLED)
b5.grid(row=5,column=1)
b6=Button(root,bd=3,width=15,text="",height=6,command=click6,state=DISABLED)
b6.grid(row=5,column=2)
b7=Button(root,bd=3,width=15,text="",height=6,command=click7,state=DISABLED)
b7.grid(row=6,column=0)
b8=Button(root,bd=3,width=15,text="",height=6,command=click8,state=DISABLED)
b8.grid(row=6,column=1)
b9=Button(root,bd=3,width=15,text="",height=6,command=click9,state=DISABLED)
b9.grid(row=6,column=2)
def start():
	b1['state']=NORMAL
	b2['state']=NORMAL
	b3['state']=NORMAL
	b4['state']=NORMAL
	b5['state']=NORMAL
	b6['state']=NORMAL
	b7['state']=NORMAL
	b8['state']=NORMAL
	b9['state']=NORMAL
st=Button(text="Click to Play",command=readname,state=NORMAL)
st.grid(row=3,column=0,columnspan=3)
root.mainloop()