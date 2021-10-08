def square(number):
    print(number * number) #return number * number
     #default return None

print(square(4))
def geet_user(first_name, last_name):
    print(f'Hii {first_name} {last_name}')
    print("Welcome aboard")


print("Start")
geet_user("shaibaz","Qaisar") #positional arguments position matters..

geet_user(last_name="Desuza" ,first_name ="Marry") #keyword arguments
#geet_user(first_name = "le","kdk") gives an error because positional arguments should be first..
print("Finish")