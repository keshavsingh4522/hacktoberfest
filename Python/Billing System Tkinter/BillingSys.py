# importing modules
from tkinter import *
from tkinter import messagebox
import datetime

# setting date and time
date = datetime.datetime.now().date()
format_date = date.strftime("%d-%m-20%y")
time = str(datetime.datetime.now().time()).split(':')
format_time = time[0]+':'+time[1]+':'+time[2][:2]


# creating an object(window) for a class Tk() in tkinter
root = Tk()

# giving title to our window
root.title("Bill")

# setting background color of root window
root.configure(bg='orange')

# list to store product name as well as product price
my_products = []


# func to add more products
def more_product():
    if len(pro_name_var.get()) == 0 or pro_price_var.get() == 0:
        messagebox.showwarning(title='Empty', message="First enter the data")
    else:
        prod_name = pro_name_var.get()
        prod_qty = pro_Qty_var.get()
        prod_price = pro_price_var.get()
        product_list = [prod_name, prod_qty, prod_price]
        my_products.append(product_list)

        products_textbox.insert(INSERT, prod_name+"\t\t\t\t  "+str(prod_qty)+"\t\t  " +
                                str(prod_price) + "\n")

        proNameEntry.delete(0, END)
        proQtyEntry.delete(0, END)
        proPriceEntry.delete(0, END)


# func to delete product from list
def delete_product():
    products_textbox.insert(INSERT, "\n\n")
    if len(pro_name_var.get()) == 0:
        messagebox.showinfo('enter','Enter Product name, Quantity, Price')
    else:
        prod_name_del = pro_name_var.get()
        prod_qty_del = pro_Qty_var.get()
        prod_price_del = pro_price_var.get()

        pro_to_del = str()

        for i in my_products:
            if i[0] == prod_name_del:
                pro_to_del = str(my_products.index(i))

        if prod_qty_del == 0:
            del my_products[int(pro_to_del)]
        else:
            my_products[int(pro_to_del)][0] = prod_name_del
            my_products[int(pro_to_del)][1] = prod_qty_del
            my_products[int(pro_to_del)][2] = prod_price_del

    proNameEntry.delete(0, END)
    proQtyEntry.delete(0, END)
    proPriceEntry.delete(0, END)


# func to close the window
def exit_window():
    my_message = messagebox.askquestion(title="Confirm Exit",message="Are you sure you want to exit?")
    if my_message == "yes":
        root.quit()


# func to get total amount for products
def total_amount_products():
    total_amount = 0
    for products in my_products:
        total_amount += products[1]*products[2]

    products_textbox.insert(INSERT, "\nTotal = " + str(total_amount) + "\n")


# func to list products or items
def show_items():
    products_textbox.insert(INSERT, "\nYour Items: \n")
    for i, j, k in my_products:
        products_textbox.insert(INSERT, i + "\t\t\t\t  " + str(j) + "\t\t  " + str(k)+"\n")


# cash return to customer
def cash_by_customer():
    total_prod_price = 0
    for products in my_products:
        total_prod_price += products[1]*products[2]
    # print(total_prod_price)
    cash_given = cash_amount_var.get()
    cash_to_customer = cash_given - total_prod_price

    products_textbox.insert(INSERT, "\nCash : " + str(cash_given) + "\nReturn : "+str(cash_to_customer)+"\n")
    cashEntry.delete(0, END)


# ******* ::Buttons:: *******

# add products
add_product = Button(root, text="Add Item", fg='black', bg='white', width=20,
                     font="helvetica 10 bold",command=more_product)
add_product.place(x=300, y=110)

# delete product
delete_prod = Button(root, text="Delete / Update", fg='black', bg='white', width=20,
                     font="helvetica 10 bold", command=delete_product)
delete_prod.place(x=300, y=140)

# get total amount
total_price = Button(root, text="Total", fg='black', bg='white', width=20,
                     font="helvetica 10 bold", command=total_amount_products)
total_price.place(x=300, y=170)

# show products
show_prod = Button(root, text="Show Item", fg='black', bg='white', width=20,
                   font="helvetica 10 bold", command=show_items)
show_prod.place(x=300, y=200)

# to close the window
close_window = Button(root, text="Close", fg='black', bg='white', width=20,
                      font="helvetica 10 bold", command=exit_window)
close_window.place(x=300, y=230)

# cash amount
cash_amt = Button(root, text="Cash", fg='black', bg='white', width=12,
                  font="helvetica 10 bold", command=cash_by_customer)
cash_amt.place(x=10, y=180)


# ******* ::Labels:: *******
proName = Label(root, text="Product Name", fg='Black', bg='#5AF310', font="helvetica 12 bold" )
proName.place(x=10, y=30)

proQty = Label(root, text="Quantity", fg='Black', bg='#5AF310', font="helvetica 12 bold" )
proQty.place(x=190, y=30)

proPrice = Label(root, text="Price", fg='Black', bg='#5AF310', width=8, font="helvetica 12 bold")
proPrice.place(x=290, y=30)

date_label = Label(root, text="Date: "+format_date, bg="#F31081", font="helvetica 10 bold")
date_label.place(x=390, y=5)

time_label = Label(root, text="Time: "+format_time, width=12, bg="#0394fc", font="helvetica 10 bold")
time_label.place(x=390, y=28)

cash_label = Label(root, text="Cash Amount", width=12, fg='Black', bg='#5AF310', font="helvetica 12 bold")
cash_label.place(x=10, y=120)

# ******* ::Entry Bars:: *******
# Name Entry
pro_name_var = StringVar()
proNameEntry = Entry(root,textvariable=pro_name_var, width=15, fg='blue', bg='yellow',
                     font="helvetica 12 bold")
proNameEntry.place(x=10, y=60)

# Quantity Entry
pro_Qty_var = IntVar()
proQtyEntry = Entry(root, textvariable=pro_Qty_var, width=5, fg='blue', bg='yellow',
                    font="helvetica 12 bold")
proQtyEntry.place(x=190, y=60)

# Price Entry
pro_price_var = IntVar()
proPriceEntry = Entry(root, textvariable=pro_price_var, width=10, fg='blue', bg='yellow',
                      font="helvetica 12 bold")
proPriceEntry.place(x=290, y=60)

# Cash Entry
cash_amount_var = IntVar()
cashEntry = Entry(root, textvariable=cash_amount_var, width=8, fg='blue', bg='yellow',
                  font="helvetica 12 bold")
cashEntry.place(x=10, y=150)


# ******* ::TextBox:: *******
# textBox to list all the product names and their prices
products_textbox = Text(root,height=15, width=60, font="helvetica 10 bold",
                        fg='black', bg='#a8328f', wrap=WORD)
products_textbox.place(x=30, y=280)

products_textbox.insert(INSERT, "Product name \t\t\t\t Qty \t\t Price \n\n")

# it is used so that no one can resize our window frame
root.resizable(False, False)

# setting geometry of our window of width=400 & length=400
root.geometry("500x600+60+60")

# it is used to present the window for all time otherwise after compilation it gets disappear
root.mainloop()