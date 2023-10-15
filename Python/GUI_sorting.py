import tkinter as tk
import random

#Function to swap two bars that will be animated
def swap(pos_0, pos_1):
    bar11, _, bar12, _ = canvas.coords(pos_0)
    bar21, _, bar22, _ = canvas.coords(pos_1)
    canvas.move(pos_0, bar21-bar11, 0)
    #canvas.itemconfig(pos_0, bar21-bar11, fill='yellow')
    canvas.move(pos_1, bar12-bar22, 0)
    #canvas.itemconfig(pos_1, bar12-bar22, fill='orange')

worker = None 

#Insertion Sort
def _insertion_sort():
    global barList
    global lengthList

    for i in range(len(lengthList)):
        cursor = lengthList[i]
        cursorBar = barList[i]
        pos = i

        while pos > 0 and lengthList[pos - 1] > cursor:
            lengthList[pos] = lengthList[pos - 1]
            barList[pos], barList[pos - 1] = barList[pos - 1], barList[pos]
            swap(barList[pos],barList[pos-1])   
            yield                                      
            pos -= 1                                   

        lengthList[pos] = cursor
        barList[pos] = cursorBar
        swap(barList[pos],cursorBar)


#Bubble Sort
def _bubble_sort():
    global barList
    global lengthList
    
    for i in range(len(lengthList) - 1):
        for j in range(len(lengthList) - i - 1):
            if(lengthList[j] > lengthList[j + 1]):
                lengthList[j] , lengthList[j + 1] = lengthList[j + 1] , lengthList[j]
                barList[j], barList[j + 1] = barList[j + 1] , barList[j]
                swap(barList[j + 1] , barList[j])
                yield        
           

#Selection Sort            
def _selection_sort():
    global barList    
    global lengthList

    for i in range(len(lengthList)):
        min = i
        for j in range(i + 1 ,len(lengthList)):
            if(lengthList[j] < lengthList[min]):
                min = j
        lengthList[min], lengthList[i] = lengthList[i] ,lengthList[min]
        barList[min] , barList[i] = barList[i] , barList[min]
        swap(barList[min] , barList[i])        
        yield


#Merge Sort
def _merge_Sort():
    return 0


#Shell Soer
def _shell_sort():
    return 0

#Triggering Fuctions

def insertion_sort():     
    global worker
    worker = _insertion_sort()
    animate()

def selection_sort():     
    global worker
    worker = _selection_sort()
    animate()

def bubble_sort():     
    global worker
    worker = _bubble_sort()
    animate()    

def merge_sort():
    return 0

def shell_sort():
    return 0

#Animation Function
def animate():      
    global worker
    if worker is not None:
        try:
            next(worker)
            window.after(10, animate)    
        except StopIteration:            
            worker = None
        finally:
            window.after_cancel(animate) 


#Generator function for generating data
def generate():
    global barList
    global lengthList
    canvas.delete('all')
    barstart = 1
    barend = 8
    barList = []
    lengthList = []

    #Creating a rectangle
    for bar in range(1, 100):
        randomY = random.randint(1, 360)
        bar = canvas.create_rectangle(barstart, randomY, barend, 365, fill='blue')
        barList.append(bar)
        barstart += 10
        barend += 10

    #Getting length of the bar and appending into length list
    for bar in barList:
        bar = canvas.coords(bar)
        length = bar[3] - bar[1]
        lengthList.append(length)

    #Maximum is colored Red
    #Minimum is colored Black
    for i in range(len(lengthList)-1):
        if lengthList[i] == min(lengthList):
            canvas.itemconfig(barList[i], fill='red')
        elif lengthList[i] == max(lengthList):
            canvas.itemconfig(barList[i], fill='green')



#Making a window using the Tk widget
window = tk.Tk()
window.title('Sorting Visualizer By Anoop')
window.geometry('1000x450')

#Making a Canvas within the window to display contents
canvas = tk.Canvas(window, width='1000', height='400')
canvas.grid(column=0,row=0, columnspan =30)

#Buttons
insert = tk.Button(window, text='Insertion Sort', command=insertion_sort)
merge = tk.Button(window, text='Merge Sort', command=merge_sort)
select = tk.Button(window, text='Selection Sort', command=selection_sort)
bubble = tk.Button(window, text='Bubble Sort', command=bubble_sort)
shuf = tk.Button(window, text='Shuffle', command=generate)
shell = tk.Button(window, text='Shell Sort', command=shell_sort)
insert.grid(column=1,row=1)
select.grid(column=2,row=1)
bubble.grid(column=3,row=1)
merge.grid(column=4,row=1)
shell.grid(column=5,row=1)
shuf.grid(column=0, row=1)

generate()
window.mainloop()
