# Python Program to demonstrate creation of Array using array creations
import array as arr

print("INTEGER ARRAY OPERATIONS:")
size = int(input(" Enter the size of Array: "))
# creating an array with integer type
lst = list()
for i in range(size):
    lst.append(int(input("Enter the  Integer Element:")))
n = arr.array(lst)

# printing array
def pr(n):
    print("The new integer array is : ", end=" ")
    for i in range(len(n)):
        print(n[i], end =", ")
    print()

def add(n,j):
    print("The Array before adding: ", end=" ")
    for i in range(len(n)):
        print(n[i], end=", ")
    print()
    #Append() method
    n.append(j)
    print("The Array After adding: ", end=" ")
    for i in range(len(n)):
        print(n[i], end=", ")
    print()

def adde(n,j,p):
    print("The Array before adding: ", end=" ")
    for i in range(len(n)):
        print(n[i], end=", ")
    print()
    #insert() method
    n.insert(p,j)
    print("The Array After adding: ", end=" ")
    for i in range(len(n)):
        print(n[i], end=", ")
    print()

def pp(n,j):
    if n:
        print("The Array before Popping: ", end=" ")
        for i in range(len(n)):
            print(n[i], end=", ")
        print()
        # pop() method
        n.pop(j)
        print("The Array After Popping: ", end=" ")
        for i in range(len(n)):
            print(n[i], end=", ")
        print()
    else:
        print("Array Empty")

def prt(n,j):
    if n:
        if j in range(len(n)):
            print("The Array before Removing: ", end=" ")
            for i in range(len(n)):
                print(n[i], end=", ")
            print()
            #remove Method
            n.remove(j)
            print("The Array After Removing: ", end=" ")
            for i in range(len(n)):
                print(n[i], end=", ")
            print()
        else:
            print("Index Out of Bound")
    else:
        print("Array Empty")

#Driver code
flag = 1
while(flag):
    print()
    print("1.Print Array\n2.Add Element using append()\n3.Add Element using insert()\n4.Pop() Element\n5.Remove Element at position\n6.Exit\n")
    option = int(input("Enter the option :"))
    if option == 1:
        pr(n)
    elif option == 2:
        i = int(input("Enter the Element to be added: "))
        add(n,i)
    elif option == 3:
        p = int(input("Enter the position to add element:"))
        i = int(input("Enter the Element: "))
        adde(n, i, p)
    elif option == 4:
        i = int(input("Enter the Index position To be popped: "))
        pp(n, i)
    elif option == 5:
        i = int(input("Enter the Element Position To be Removed: "))
        prt(n, i)
    elif option == 6 :
        flag = 0






