from tkinter import *
import pyshorteners
import clipboard


window = Tk()

#set deafault window size
window.geometry("400x200") # width x height

# make window not resizable 
window.resizable(False, False)  # not resizable in x and y 

# app title
window.title("URL Shortener")



# url entry
url_input = Entry(window, font=("Helvetica","16"))
url_input.grid(row=1, column=2, pady=6)


#label shortened url
str_url = StringVar(window)

shortened_url = Label(window, textvariable=str_url, font=("Helvetica","16"), fg="#fff", bg="#1abc9c")
shortened_url.grid(row=3, column=2, pady=6)


# copy short url function
def copy_short_url():
  try:
    clipboard.copy(str_url.get())
    print("Url copied successfully !!")
  except:
    str_url.set("Something wrong try again !!")

# Copy short url button
copy_btn = Button(window, text="Copy", bg="#34495e", fg="#fff", font=("Helvetica","12"), command=copy_short_url)
copy_btn.grid(row=3, column=3, pady=6, padx=10)



#short url function
def short_url():
  try:
    s = pyshorteners.Shortener()
    url = url_input.get()
    final_result = s.tinyurl.short(url)
    str_url.set(final_result)
    url_input.delete(0, END) # clear input 
  except:
    str_url.set("Enter url please !! ")


#click button to short url
btn = Button(window, text="Short Url", padx=8, pady=4, bg="#2ecc71", fg="#fff", font=("Helvetica","16"), activebackground="#16a085", command=short_url)
btn.grid(row=2, column=2, pady=6)

window.mainloop()
