from tkinter import *
from tkinter import messagebox
from random import choice, randint, shuffle
import json

# ---------------------------- PASSWORD GENERATOR ------------------------------- #

def generate_pass():
    letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
    numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

    pass_letters = [choice(letters) for _ in range(randint(5,8))]
    pass_num = [choice(numbers) for _ in range(randint(4,7))]
    pass_sym = [choice(symbols) for _ in range(randint(3,6))]

    pass_list = pass_letters + pass_num + pass_sym
    shuffle(pass_list)

    password = "".join(pass_list)
    pass_entry.insert(0,password)


# ---------------------------- SAVE PASSWORD ------------------------------- #

def save():

    website = web_entry.get().title()
    email = email_entry.get()
    password = pass_entry.get()

    new_data = {
        website:{
            "Email" : email,
            "Password" : password
        }
    }

    if len(website)==0 or len(email) < 10  or len(password)==0:
        messagebox.showinfo(title="Oops!!", message="please make sure you have fill every entry.\nAnd in the standard format.")


    else:
        is_ok = messagebox.askokcancel(title= f"For {website} ", message= f"     there are the details you entered :\n\n     Email : {email} \n     Password : {password} \n\nIs it okay to save..?")

        if is_ok:
            
            try:
                with open ("data.json", "r") as data_file:
                    data = json.load(data_file)

            except FileNotFoundError:
                with open("data.json", "w") as data_file:
                    json.dump(new_data, data_file, indent=4)
            
            else:
                data.update(new_data)

                with open("data.json", "w") as data_file:
                    json.dump(data, data_file, indent=4)

            finally:
                web_entry.delete(0, END)
                pass_entry.delete(0, END)


# ---------------------------- FIND PASSWORD ------------------------------- #

def find_pass():
    website = web_entry.get().title()

    try:
        with open("data.json", "r") as data_file:
            data = json.load(data_file)

    except FileNotFoundError:
        messagebox.showinfo(title= "Ohho!!", message= "You have'nt stored any data.")

    else:
        if website in data:
            email = data[website]["Email"]
            password = data[website]["Password"]

            messagebox.showinfo(title= f"Credentials regarding {website}", message= f"Email :  {email} \nPassword : {password}")
    
        else:
            messagebox.showinfo(title="Ohho!!", message= f"You have'nt stored any Credentials regarding {website}")


# ---------------------------- UI SETUP ------------------------------- #

window = Tk()
window.title("PASSWORD MANAGER...")
window.minsize(height=600, width=600)
window.config(padx=100, pady=50, bg="black")

canvas = Canvas(height=200, width=200, bg="black", highlightbackground="black")
logo_image = PhotoImage(file="lock.png")
canvas.create_image(100,127, image = logo_image)
canvas.grid(row=0, column=1, pady=50)

#websites ka -->

web_label = Label(text="Website : ", bg="black", fg="chartreuse", font=("arial", 15) )
web_label.grid(row=1, column=0)
web_entry = Entry(width=35)
web_entry.grid(row=1, column=1)
web_entry.focus()

#email ka -->

email_label = Label(text="Email/ phone no/ username : ", font=("arial", 15) ,bg="black", fg="chartreuse" )
email_label.grid(row=2, column=0)
email_entry = Entry(width=35)
email_entry.grid(row=2, column=1)
# email_entry.insert(END, "abc123@abc.com")     ye krne se pehle se hi entry main ye likha aaega if u want u can try it


#password ka -->

pass_label = Label(text="Password : ", font=("arial", 15) ,bg="black", fg="chartreuse"  )
pass_label.grid(row=3, column=0)
pass_entry = Entry(width=35)
pass_entry.grid(row=3, column=1, padx=10)


#buttons -->

generate_pass_button = Button(text="generate key", bg="black", fg="white", width=13, command=generate_pass )
generate_pass_button.grid(row=3, column=2)

add_button = Button(text="ADD" , width=52, bg="black", fg="white", command=save )
add_button.grid(row=4, column=0, columnspan=2, pady=30)

search_button = Button(text="search credentials", bg="black", fg="white", width=13, command=find_pass )
search_button.grid(row=1, column=2)


window.mainloop()