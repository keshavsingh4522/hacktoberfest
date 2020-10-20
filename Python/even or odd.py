#simple way of finding odd and even.
num = int(input("Enter any integer number: ")) #num variable to store any integer number
mod = num % 2                                  #mod variable to store value
if mod > 0:                                    #condition for odd and even
    print("This is an odd number.")
else:
    print("This is an even number.")
