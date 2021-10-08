import random
from tkinter import *
from tkinter import messagebox
import pyperclip
import json
# ---------------------------- PASSWORD GENERATOR ------------------------------- #
def gen_password():
    password_entry.delete(0, END)
    letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
               'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
               'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
    numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

    nr_letters = random.randint(6, 8)
    nr_symbols = random.randint(2, 4)
    nr_numbers = random.randint(2, 4)

    password_letters = [random.choice(letters) for char in range(nr_letters)]
    password_numbers = [random.choice(numbers) for num in range(nr_numbers)]
    password_symbols = [random.choice(symbols) for sym in range(nr_symbols)]
    password_list = password_symbols + password_numbers + password_letters

    random.shuffle(password_list)

    password = "".join(password_list)

    password_entry.insert(0, password)
    pyperclip.copy(password)

# ---------------------------- SAVE PASSWORD ------------------------------- #
def save():
    w_e = website_entry.get()
    p_e = password_entry.get()
    u_e = username_entry.get()
    data = {w_e:{"Username": u_e,
                 "Password": p_e}
            }
    if len(w_e) == 0:
        messagebox.showinfo(message = "You have left the website field empty. Please fill the website details" )

    elif len(u_e) == 0:
        messagebox.showinfo(message="You have left the Username field empty. Please fill the Username details")

    elif len(p_e) == 0:
        messagebox.showinfo(message="You have left the Password field empty. Please fill the Password details")

    else:
        is_ok = messagebox.askokcancel(title = f"{w_e}", message = f"You have entered the following details.\n"
                                                                       f"Website: {w_e} "
                                                                       f"\n Username/Email:{u_e}"
                                                                   f" \n Password: {p_e}")
        if is_ok:
            try:
                with open("data.json", "r") as data_file:
                    d = json.load(data_file)
            except FileNotFoundError:
                with open("data.json", "w") as data_file:
                    json.dump(data, data_file)
            else:
                d.update(data)
                with open("data.json", "w") as data_file:
                    json.dump(d, data_file, indent = 4)
            finally:
                website_entry.delete(0, END)
                password_entry.delete(0, END)
                username_entry.delete(0, END)


# ---------------------------Search DATA -----------------------------

def search():
    w_e = website_entry.get()
    with open("data.json", "r") as data_file:
        json_dict = json.load(data_file)
        try:
            data_dict = json_dict[w_e]

        except KeyError:
            messagebox.showinfo(title="Details not found", message=f"The details of website you entered are not found."
                                                                   f"Please make sure you enter correct details")
        else:
            u_e = data_dict["Username"]
            p_e = data_dict["Password"]
            copy_pass = messagebox.askyesno(title = "Your data", message = f"Username/Email: {u_e} \n Password: {p_e}\n"
                                                                           f"Do you want to copy password to clipboard?")
            if copy_pass:
                pyperclip.copy(p_e)

        finally:
            website_entry.delete(0, END)



# ---------------------------- UI SETUP -------------------------------

window = Tk()
window.config(bg = "white", padx = 20, pady = 20)
window.title("Password Manager")
window.minsize(500, 500)
canvas = Canvas(width = 200, height = 200, highlightthickness = 0)
lock_image = PhotoImage(file = "logo.gif")
canvas.create_image(100, 100, image = lock_image)
canvas.grid(row = 0, column = 1)

website_label = Label(text = "Website:")
website_label.grid(row = 1, column = 0)

website_entry = Entry(width = 22)
website_entry.focus()
website_entry.grid(row = 1, column = 1, columnspan = 1)

username_label = Label(text = "Email/Username:")
username_label.grid(row = 2, column = 0)

username_entry = Entry(width = 35)
username_entry.grid(row = 2, column = 1, columnspan = 2)

password_label = Label(text = "Password:")
password_label.grid(row = 3, column = 0)

password_entry = Entry(width = 21)
password_entry.grid(row = 3, column = 1, columnspan = 1,  padx  = 10)

generate_button = Button(text = "Generate Password", width = 13, command = gen_password)
generate_button.grid(row = 3, column = 2)

add_button = Button(text = "Add", width = 36, command = save )
add_button.grid(row = 4, column = 1, columnspan = 2)

search_button = Button(text = "Search", width = 12, command = search)
search_button.grid(row = 1, column = 2, columnspan = 2)
window.mainloop()