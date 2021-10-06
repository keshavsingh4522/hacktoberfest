# Python program to demonstrate
# creating a new file
  
  
# importing module
import os
  
# path of the current script
path = 'D:/Pycharm projects/gfg'
  
# Before creating
dir_list = os.listdir(path) 
print("List of directories and files before creation:")
print(dir_list)
print()
  
# Creates a new file
with open('myfile.txt', 'w') as fp:
    pass
    # To write data to new file uncomment
    # this fp.write("New file created")
  
# After creating 
dir_list = os.listdir(path)
print("List of directories and files after creation:")
print(dir_list
