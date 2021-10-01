#It Doesn't Comes Under Bubblesort
import time as t
print("           Brought To You by ")
t.sleep(0.5)
print("*"*40)
t.sleep(0.5)

print("      ____                _      _ ")
print("     |  _ \ ___ _ __ ___ (_) ___| |")
print("     | |_) / _ \ '_ ` _ \| |/ _ \ |")
print("     |  _ <  __/ | | | | | |  __/ |")
print("     |_| \_\___|_| |_| |_|_|\___|_|")                              
print("            Insta:@jrxag_official      ")
t.sleep(0.5)
print("*"*40)
t.sleep(0.5)
print("\n--------BUBBLE SORT A LIST--------")

#----------------------------------------------


#Main Definiton Of The BubbleSort

def sort(nums):
  for i in range(len(nums)-1,0,-1):
    for j in range(i):
      if nums[j]>nums[j+1]:
        temp=nums[j]
        nums[j]=nums[j+1] 
        nums[j+1]=temp
  return nums  


#__main__
lst = [] 
n = int(input("Enter number of elements : ")) 
for i in range(0, n): 
    ele = int(input()) 
    lst.append(ele)   
bsort=sort(lst)
print("Here",bsort)    


#appreciation
print("*"*40)
print("Thanks, Checkout My Profile For More")
t.sleep(2)
print("Leave A Star, That Motivates Me A Lot")
t.sleep(1)
print("       _______  __   __  _______ ")
print("      |  _    ||  | |  ||       |")
print("      | |_|   ||  |_|  ||    ___|")
print("      |       ||       ||   |___ ")
print("      |  _   | |_     _||    ___|")
print("      | |_|   |  |   |  |   |___ ")
print("      |_______|  |___|  |_______|")
