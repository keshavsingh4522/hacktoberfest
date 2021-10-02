import tkinter as tk
from tkinter.messagebox import *
import requests , json, base64

def getIcon(icon_id):
    url = 'http://openweathermap.org/img/wn/{icon}.png'.format(icon=icon_id)
    response = requests.get(url, stream=True)
    return base64.encodebytes(response.raw.read())

def showWeather(data1):
    global x
    newScreen = tk.Toplevel()
    newScreen.title('Weather Result')
    newScreen.geometry('200x300+550+250')
    newScreen.resizable(0, 0)
    icon_image = tk.PhotoImage(data=data1[4])
    icon_label = tk.Label(newScreen,image=icon_image)
    icon_label.place(x=0, y=15)

    desc = tk.Label(newScreen, text=data1[5], font=('Times', 15, 'bold'))
    desc.place(x=50, y=20)

    location = tk.Label(newScreen, text=f"Location : {data1[0]}", font=('Times', 13))
    location.place(x=20, y=70)

    temperature = tk.Label(newScreen, text=f"Temperature : {data1[1]}°C", font=('Times', 13))
    temperature.place(x=20, y=110)

    current_humidiy = tk.Label(newScreen, text=f"Humidity: {data1[2]}%", font=('Times', 13))
    current_humidiy.place(x=20, y=150)

    current_pressure = tk.Label(newScreen, text=f"Pressure : {data1[3]}", font=('Times', 13))
    current_pressure.place(x=20, y=190)

    close_button = tk.Button(newScreen, text='Close', command= lambda : [city.delete(0, tk.END), newScreen.destroy()],font=('Times', 15, 'bold'), bg='#121212', fg="#fafef8")
    close_button.place(x=70, y=230)

    newScreen.mainloop()
    
def findWeather():
    city_name = city.get()        
    complete_url = base_url + "appid=" + api_key + "&q=" + city_name
    response = requests.get(complete_url)
    x = response.json()

    if x["cod"] != "404":
        y = x["main"]
        current_temperature = y["temp"]
        current_pressure = y["pressure"]
        current_humidiy = y["humidity"]
        z = x["weather"]
        weather_description = z[0]["description"]
        temperature = str(current_temperature-273.15)[0:5]
        icon = getIcon(z[0]['icon'])
        showWeather([city_name, temperature, current_humidiy, current_pressure, icon, z[0]['description']]) 
        

    else:
        showerror('Error','City Not Valid!\nPlease Check!')
        city.delete(0,tk.END)

# main
# basic info
api_key = "YOUR API KEY HERE"
base_url = "http://api.openweathermap.org/data/2.5/weather?"
# GUI
root = tk.Tk()
root.title('Weather App')
root.geometry('450x250+550+250')
root.resizable(0, 0)
bg_picture = tk.PhotoImage(file='bg.png')
bg = tk.Label(root,image=bg_picture)
bg.pack()
tit_le = tk.Label(root,text="Enter City Below",font=('Times', 20, 'bold'),bg = '#1f252f',fg = '#fafef8')
tit_le.place(x=130,y=75)
city = tk.Entry(root, font=('Times', 15))
city.place(x=125,y=140)
city.focus()
cta_button = tk.Button(root,text='Find Weather',command=findWeather)
cta_button.place(x=185,y=180)
root.mainloop()