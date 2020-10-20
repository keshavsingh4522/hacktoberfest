from pyrebase import *
from getpass import getpass
from tkinter import *
from pprint import pprint
import details
from time import *

firebaseConfig = {
    apiKey: "",                 #Add Your Firebase API in ""
    authDomain: "",             #Add Your Firebase authdomain in ""
    databaseURL: "",            #Add Your Firebase databaseURL in ""
    projectId: "",              #Add Your Firebase projectID in ""
    storageBucket: "",          #Add Your Firebase storageBucket in ""
    messagingSenderId: "",      #Add Your Firebase messagingSenderId in ""
    appId: ""                   #Add Your Firebase appId in ""
  }

for i in firebaseConfig:
    if firebaseConfig[i] == '' or firebaseConfig[i].isspace():
        print('Please fill up the spaces where requested')
        exit

try:
    firebase = initialize_app(firebaseConfig)
except:
    print('Please Check the details again or check your Internet connection')
else:
    auth = firebase.auth()





app = Tk()
app.title('Weather_App Login Panel')
app.config(bg='lightblue')
app.geometry('1280x720')
app.minsize(1280*2//3, 720*2//3)
frame = LabelFrame(app,
                    bg ='#6dd1e3',
                    height = 720//3,
                    width = 1280//3,
                    borderwidth = 20,
                    relief = 'groove')

frame.place(relx = 0.25, rely = 0.2, relwidth = 0.5)



def forgot(): #Try to add a new window

    app1 = Tk()
    app1.geometry(str(1280*2//3)+'x'+str(720*2//3))
    app1.config(bg = '#6dd1e3')
    app1.title('Reset Password')
    app1_label = Label(app1,
                    text = 'Reset Password',
                    bg = 'yellow',
                    font = ('Times', 30, 'bold'))
    app1_label.place(relx = 0,
                    rely = 0,
                    relwidth = 1)

    f_pass_label = Label(app1,
                    text = 'Enter your Email',
                    bg = '#6dd1e3',
                    font = ('Helvetica', 20,'bold'))
    f_pass_label.place(relx = 0.27,
                    rely = 0.3,
                    relwidth = 0.5)

    f_pass_entry = Entry(app1)
    f_pass_entry.place(relx = 0.4,
                    rely = 0.4,
                    relwidth = 0.25,
                    relheight = 0.05)
    f_pass_entry.focus()

    def forgot_pass():

        try:
            user = auth.send_password_reset_email(f_pass_entry.get())
            f_pass_label['text'] = "Check your Inbox"

        except:
            f_pass_label['text'] = "Email is not Registered"


    f_pass_button = Button(app1,
                    text = 'Send Email',
                    bg = 'lightgreen',
                    font = ('Helvetica',20,'bold'),
                    command = forgot_pass)
    f_pass_button.place(relx = 0.4,
                    rely = 0.6,
                    relwidth = 0.25)


def signup():

    if(signup_label['text'] == "Don't have an Account?"):
        signup_label['text'] = "Have an Account?"
        signup_label.place(relx = 0.4, rely = 0.75)
        signup_button['text'] = "Login"
        signup_button.place(relx = 0.45, rely = 0.85)
        login_button['text'] = "Signup"
        Login['text'] = 'Signup'
    else:
        signup_label['text'] = "Don't have an Account?"
        signup_label.place(relx = 0.35 ,rely = 0.75)
        signup_button['text'] = 'Create Account'
        signup_button.place(relx = 0.4 ,rely = 0.85)
        login_button['text'] = 'Login'
        Login['text'] = 'Login'
Label1 = Label(app, text ='',
                bg = 'lightblue',
                fg = 'black',
                font = ('Helvetica', 15, 'bold', 'underline'))
Label1.place(relx = 0.4,
            rely = 0.15)

def login():
    Label1['text'] = ''
    email = email_entry.get()
    password = password_entry.get()
    if(login_button['text'] == 'Signup'):

        try:
            user = auth.create_user_with_email_and_password(email, password)
            auth.send_email_verification(user['idToken'])
            while(True):
                a = auth.get_account_info(user['idToken'])
                b = a['users'][0]['emailVerified']
                if(b == True):
                    break
                else:
                    sleep(5)
            app.destroy()
            details.weather()

        except:
            Label1['text'] = 'Email Already in Use, try Forgot Password'
            sleep(5)


    else:
        try:
            user = auth.sign_in_with_email_and_password(email, password)
            a = auth.get_account_info(user['idToken'])
            b = a['users'][0]['emailVerified']
            if(b == True):
                app.destroy()
                details.weather()
            else:
                Label1['text'] = "Your account hasn't been Verified"

        except:
            Label1['text']='Email id and password did not Matched'
            print('Kuch Toh gadab hai')
            sleep(5)





email_entry = Entry(frame)
email_entry.place(relx = 0.4,
                rely = 0.1,
                relwidth = 0.5)

password_entry = Entry(frame)
password_entry.place(relx = 0.4,
                rely = 0.5,
                relwidth = 0.5)

email_label = Label(frame,
            text = 'Enter Your Email',
            font = ('Helvetica', 12,'bold'),
            bg = '#6dd1e3')
email_label.place(relx = 0.03,
            rely = 0.1)

password_label = Label(frame,
                text = 'Enter Your Password',
                font = ('Helvetica', 12,'bold'),
                bg = '#6dd1e3')
password_label.place(relx = 0,
                rely = 0.5)

login_button = Button(frame,
                text = 'Login',
                bg = 'lightgreen',
                font = ('Helvetica',20,'bold'),
                command = login)
login_button.place(relx = 0.35,
                rely = 0.7)

signup_label = Label(app,
                text = "Don't have an Account?",
                font = ('Helvetica', 20,'bold'),
                bg = 'lightblue')
signup_label.place(relx = 0.35 ,
                rely = 0.75)

signup_button = Button(app,
                    text = 'Create Account',
                    bg = '#6dd1e3',
                    font = ('Helvetica',20,'bold'),
                    command = signup)
signup_button.place(relx = 0.4,
                rely = 0.85)

forgot_button = Button(app,
                    text = 'Forgot Password?',
                    bg = '#6dd1e3',
                    font = ('Helvetica',20,'bold'),
                    command = forgot)
forgot_button.place(relx = 0.37,rely = 0.6)


Login = Label(app,
            text = 'Login',
            font = ('New Roman Times',40,'bold'),
            bg = 'yellow')
Login.place(relx = 0,
        rely = 0,
        relwidth = 1)

app.mainloop()
