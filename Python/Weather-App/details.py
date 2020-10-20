#!/usr/bin/python3
import PIL.Image, PIL.ImageTk
from tkinter import *
from owmdata import *
import mysql.connector

#mydb = mysql.connector.connect(host = 'localhost', user = 'root', passwd = 'admin', database = 'Weather_App')
#cursor = mydb.cursor()

def weather():
    app = Tk()

    app.title('Weather APP')

    #####Defining Geometry#####
    app.geometry('1280x720')
    app.minsize(1280*2//3, 720*2//3)

    ##### Adding Background Image #####
    bg_image = PhotoImage(file = './landscape.png')
    bg_label = Label(app, image = bg_image)
    bg_label.place(relwidth = 1, relheight = 1)

    def open_image(icon):
        size = int(frame.winfo_height()*0.25)
        img = PIL.ImageTk.PhotoImage(PIL.Image.open('./img/'+icon+'.png').resize((size, size)))
        weather_icon.delete("all")
        weather_icon.create_image(0,0, anchor='nw', image=img)
        weather_icon.image = img


    ##### Defining function of a Button #####
    def show():

        a = entry.get()
        b = a.capitalize().split()
        c = ''
        for i in b:
            c += ' '+i.capitalize()
        frame['text'] = 'Weather in'+c
        data = weather_info(a)[0]
        Text = ''
        for i in data:
            Text +='\n'+i
        out.config(text = Text)
        icon = weather_info(a)[1][0]
        open_image(icon)



        #out.config(text = 'Some Error Occured')




    ##### Creating A Frame ######
    frame = LabelFrame(app,text = 'Get Information Here',
                        font = ('Helvetica',20,'bold'),
                        bg ='#6dd1e3',
                        height = 300,
                        width = 650,
                        borderwidth = 20,
                        relief = 'groove')

    frame.place(relx = 0.03,
                rely = 0.08)

    ##### Entry Box for City ######
    entry = Entry(app)

    entry.place(relx = 0.8,
                rely = 0.1)

    entry.focus()

    ##### Creating Button To Display Weather#####
    button = Button(app, text = 'Get Weather',
                    font = ('Helvetica',18, 'bold'),
                    command = show)

    button.place(relx = 0.8,
                rely = 0.35)

    ##### Creating Button To Show History data Of User #####
    History_Button = Button(app, text = 'Show History',
                            font = ('Helvetica',17, 'bold'))
    History_Button.place(relx = 0.8,
                        rely = 0.5)

    ##### Printing Results #####
    out = Label(frame, text = '',
                font = ('Times',20,'bold'),
                justify = 'left',
                bg = '#6dd1e3')

    out.place(relx = 0.02,
            rely = 0.02)

    weather_icon = Canvas(frame, bg='#6dd1e3',
                        highlightthickness=0.2)

    weather_icon.place(relx = 0.75,
                    rely = 0.1,
                    relheight = 0.3,
                    relwidth = 0.2)

    app.mainloop()
