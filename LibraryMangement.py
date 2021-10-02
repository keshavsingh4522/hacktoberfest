#Modules
import mysql.connector

#Making Database in MySQL
def MakeDatabase():
    sql=mysql.connector.connect(host="localhost",user="root",passwd="root")
    mydb=sql.cursor()
    try:
        mydb.execute("create database LibraryManagement;")
    except mysql.connector.errors.DatabaseError:
        try:
            mydb.execute("use LibraryManagement;")
            mydb.execute("create table books(Code varchar(10) primary key,Name char(30),Author char(30),Stock int(10));")
            mydb.execute("create table members(BookCode varchar(10),Member char(30),Date varchar(10));")
        except mysql.connector.errors.ProgrammingError:
            print("The Database and Table already exsist, Try another operation.")
            sql.commit()
        else:
            sql.commit()
            print("Created Table for Books Succesfully")
    else:
        mydb.execute("use LibraryManagement;")
        mydb.execute("create table books(Code varchar(10) primary key,Name char(30),Author char(30),Stock int(10));")
        mydb.execute("create table members(BookCode varchar(10),Member char(30),Date varchar(10));")
        sql.commit()
        print("Created Database and Table for Library Management Succesfully")
#Connecting MySQL
def ConnectSQL():
    global a
    global b
    a=mysql.connector.connect(host="localhost",user="root",passwd="root",database="LibraryManagement")
    b=a.cursor()

#Fetching Output
def Fetch(o):
    global d
    a=mysql.connector.connect(host="localhost",user="root",passwd="root",database="LibraryManagement")
    b=a.cursor()
    b.execute(o)
    d=b.fetchall()
    
#Library Menu
while True:
    print("\n\tLIBRARY MENU\n")
    print(" 1.CREATE NEW DATABASE")
    print(" 2.ADD BOOK")
    print(" 3.ISSUE BOOK")
    print(" 4.SUMBIT BOOK")
    print(" 5.DELETE BOOK")
    print(" 6.DISPLAY BOOKS DATA")
    print(" 7.DISPLAY ISSUED BOOKS")
    print(" 8.EXIT\n")

    c=int(input("Enter your Operation: "))
    print()

    #Create New Database
    if c==1:
        MakeDatabase()

    #Add Book
    elif c==2:
        ConnectSQL()
        w=input("Enter Book Code: ")
        x=input("Enter Book Name: ")
        y=input("Enter Author Name: ")
        z=int(input("Enter Total no. of Books in stock: "))
        b.execute("insert into Books(Code,Name,Author,Stock) VALUES('{}','{}','{}',{})".format(w,x,y,z))
        a.commit()
        print("\nSuccessfully Saved the Book Data.")

    #Issue Book
    elif c==3:
        ConnectSQL()
        e=0
        x=input("Enter Book Code: ")
        y=input("Enter Member Name: ")
        z=input("Enter Issued Date: ")
        o="select Code,Stock from Books;"
        Fetch(o)
        for i in d:
            if i[0]==x and i[1]>0:
                b.execute("insert into Members(BookCode,Member,Date) VALUES('{}','{}','{}')".format(x,y,z))
                b.execute("update Books set Stock=Stock-1 where Code='{}';".format(x))
                a.commit()
                print("\nSuccessfully Issued the Book with the Name",y)
                break
            elif i[0]==x and i[1]==0:
                print("\nThe required Book is out of Stock.")
                a.commit()
                break
            elif e<len(d):
                e=e+1
            if e==len(d):
                print("\nBook is Not Available In Library.")
                a.commit()

    #Sumbit Book
    elif c==4:
        ConnectSQL()
        e=0
        x=input("Enter Book Code: ")
        y=input("Enter Member Name: ")
        o="select * from Members;"
        Fetch(o)
        for i in d:
            if i[0]==x and i[1]==y:
                b.execute("delete from Members where BookCode='{}' and Member='{}';".format(x,y))
                b.execute("update Books set Stock=Stock+1 where Code='{}';".format(x))
                a.commit()
                print("\nSuccessfully Sumbitted the Book.")
                break
            elif e<len(d):
                e=e+1
            if e==len(d):
                print("\nBook is Not Available In Library.")
                a.commit()

    #Delete Book
    elif c==5:
        ConnectSQL()
        x=input("Enter Book Code to Delete: ")
        b.execute("delete from Books where Code='{}';".format(x))
        a.commit()
        print("\nDeleted the Book Sucessfully.")

    #Display Issued Books
    elif c==7:
        ConnectSQL()
        o="select * from Members;"
        Fetch(o)
        print("('BookCode','Members','DateIssued')")
        for i in d:
            print(i)

    #Exit
    elif c==8:
        break

    #Display All Books Data
    else:
        ConnectSQL()
        o="select * from Books;"
        Fetch(o)
        print("('BookCode','BookName','Author','Quantity')")
        for i in d:
            print(i)

#end
