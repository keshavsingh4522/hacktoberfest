from tkinter import *
from tkinter import messagebox


def get_height():
    '''
       This function gets height value from Entry field
    '''
    height = float(ENTRY2.get())
    return height


def get_weight():
    '''
       This function gets weight value from Entry field
    '''
    weight = float(ENTRY1.get())
    return weight


def calculate_bmi(a=""):   # "a" is there because the bind function gives an argument to the function....
    print(a)
    '''
      This function calculates the result
    '''
    try:
        height = get_height()
        weight = get_weight()
        height = height / 100.0
        bmi = weight / (height ** 2)
    except ZeroDivisionError:
        messagebox.showinfo("Result", "Please enter positive height!!")
    except ValueError:
        messagebox.showinfo("Result", "Please enter valid data!")
    else:
        if bmi <= 15.0:
            res = "Your BMI is " + str(bmi) + "\nRemarks: Very severely underweight!!"
            messagebox.showinfo("Result", res)
        elif 15.0 < bmi <= 16.0:
            res = "Your BMI is " + str(bmi) + "\nRemarks: Severely underweight!"
            messagebox.showinfo("Result", res)
        elif 16.0 < bmi < 18.5:
            res = "Your BMI is " + str(bmi) + "\nRemarks: Underweight!"
            messagebox.showinfo("Result", res)
        elif 18.5 <= bmi <= 25.0:
            res = "Your BMI is " + str(bmi) + "\nRemarks: Normal."
            messagebox.showinfo("Result", res)
        elif 25.0 < bmi <= 30:
            res = "Your BMI is " + str(bmi) + "\nRemarks: Overweight."
            messagebox.showinfo("Result", res)
        elif 30.0 < bmi <= 35.0:
            res = "Your BMI is " + str(bmi) + "\nRemarks: Moderately obese!"
            messagebox.showinfo("Result", res)
        elif 35.0 < bmi <= 40.0:
            res = "Your BMI is " + str(bmi) + "\nRemarks: Severely obese!"
            messagebox.showinfo("Result", res)
        else:
            res = "Your BMI is " + str(bmi) + "\nRemarks: Super obese!!"
            messagebox.showinfo("Result", res)


if __name__ == '__main__':
    TOP = Tk()
    
    TOP.bind("<Return>", calculate_bmi)
    
    TOP.geometry("400x300")
    
    TOP.configure(background="#363332")
    
    TOP.title("BMI Calculator")
    
    TOP.resizable(width=False, height=False)
    
    LABLE = Label(TOP, bg="#363332", text="Welcome to BMI Calculator", font=("Helvetica", 18, "bold"), pady=10, fg="#9ea1b0")
    LABLE.place(x=45, y=0)
    LABLE1 = Label(TOP, bg="#363332", text="Enter Weight (in kg):", bd=6,
                   font=("Helvetica", 12, "bold"), pady=5, fg="#edeff7", relief="flat")
    LABLE1.place(x=75, y=55)
    ENTRY1 = Entry(TOP, bd=1, width=6, font="Roboto 11")
    ENTRY1.place(x=255, y=60)
    LABLE2 = Label(TOP, bg="#363332", text="Enter Height (in cm):", bd=6,
                   font=("Helvetica", 12, "bold"), pady=5, fg="#edeff7", relief="flat")
    LABLE2.place(x=75, y=116)
    ENTRY2 = Entry(TOP, bd=1, width=6, font="Roboto 11")
    ENTRY2.place(x=255, y=121)
    BUTTON = Button(bg="#bd8ff2", bd=3, text="Calculate BMI", padx=30, pady=5, command=calculate_bmi,
                    font=("Roboto", 20, "italic"), relief="flat")
    BUTTON.place(x=70, y=200)
    TOP.mainloop()