# Importing required dependencies

from tkinter import *
from tkinter import ttk
import random

from bubbleSort import bubblesort_Alg
from mergeSort import mergesort_Alg
from quickSort import quicksort_Alg

# Intialize tkinter
window = Tk()
height = 900
width = 700
window.title('Sorting Visualizer')
window.config(bg='green')
window.maxsize(height, width)

# Variables using tkinter's StringVar
algoSelected = StringVar()
data = []


def draw(data, color):
    # When we come to this function we need to clear the canvas so the bars dont keep on adding in canvas

    canvas.delete('all')

    # Now lets draw
    x_wdt = 0
    can_hgt = 480
    can_wdt = width
    x_wdt = can_wdt/(len(data)+1)
    offset = 20
    spacing = 10
    # We need to normalize data
    normData = [i/max(data) for i in data]
    for i, hgt in enumerate(normData):
        # top left
        x0 = i*x_wdt+offset+spacing
        y0 = can_hgt-hgt*(can_hgt-40)
        # bottom right
        x1 = (i+1)*x_wdt+offset
        y1 = can_hgt
        canvas.create_rectangle(x0, y0, x1, y1, fill=color[i])
        #canvas.create_text(x0+2, y0, anchor=SW, text=str(data[i]))
    window.update_idletasks()


def Run():
    global data
    print('[INFO] Algorithm {} is selected....'.format(algoSelected.get()))
    minValue = int(minEntry.get())
    maxValue = int(maxEntry.get())
    size = int(sizeEntry.get())

    data = []
    for _ in range(size):
        data.append(random.randrange(minValue, maxValue+1))

    draw(data, ['blue' for x in range(len(data))])


def StartVisualize():
    print("[INFO] Visualization Started.....")
    global data
    if not data:
        return
    if(menu.get() == 'Bubble Sort'):
        bubblesort_Alg(data, draw, speed.get())
    elif(menu.get() == 'Merge Sort'):
        mergesort_Alg(data, draw, speed.get())
    elif(menu.get() == 'Quick Sort'):
        quicksort_Alg(data, 0, len(data)-1, draw, speed.get())

# Frame layout


UI = Frame(window, width=width, height=200, bg='yellow')
UI.grid(row=0, column=0, padx=10, pady=5)

canvas = Canvas(window, width=width, height=480, bg='white')
canvas.grid(row=1, column=0, padx=10, pady=5)

# So settings area is UI in yellow color
# Visualizing area is Canvas in white

# UI setup


# Input Sliders
# First Row Column One
sizeEntry = Scale(UI, from_=4, to=100, length=140,
                  resolution=1, orient=HORIZONTAL, label='Size')
sizeEntry.grid(row=0, column=0, padx=5, pady=5, sticky=W)

# First Row Column Two
minEntry = Scale(UI, from_=1, to=20, length=140,
                 resolution=1, orient=HORIZONTAL, label='Minimum Value')
minEntry.grid(row=0, column=1, padx=5, pady=5, sticky=W)

# First Row Column Three
maxEntry = Scale(UI, from_=30, to=200, length=140,
                 resolution=1, orient=HORIZONTAL, label='Maximum Value')
maxEntry.grid(row=0, column=2, padx=5, pady=5, sticky=W)

# First Row Column Four
Button(UI, text='     Run     ', command=Run, bg='blue').grid(
    row=0, column=3, padx=5, pady=5)


#  Second Row Column One
Label(UI, text='   Algorithms Available:', bg='yellow').grid(
    row=1, column=0, padx=5, pady=5, sticky=W)  # sticky=W means left aligned.

# Second Row Column Two
menu = ttk.Combobox(UI, textvariable=algoSelected, values=[
                    'Quick Sort', 'Merge Sort', 'Bubble Sort'])
menu.grid(row=1, column=1, padx=0, pady=0)
menu.current(0)

# Second Row Column Three
speed = Scale(UI, from_=0.0001, to=1.0, length=140, digits=5,
              resolution=0.0002, orient=HORIZONTAL, label='Select Speed [s]')
speed.grid(row=1, column=2, padx=5, pady=5)
# Second Row Column Four
Button(UI, text='Start Visualizing', command=StartVisualize, bg='blue').grid(
    row=1, column=3, padx=5, pady=5)

window.mainloop()
