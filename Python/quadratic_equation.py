# python program to solve quadratic equation

import math

string = """\n\nEnter the values for quadratic equation
Format: Ax² + Bx + C = 0
(Note: If the number on RHS of '=' is not 0, subtract it from the C constant on the LHS

Ex: BEFORE: 1x² + 2x + 3 = 4
    AFTER : 1x² + 2x + (3-4) = 0
            1x² + 2x - 1 = 0
            
                OR
        (IF NEGATIVE NUMBER)
                
    BEFORE: 1x² + 2x + 3 = -4 
    AFTER : 1x² + 2x + (3-(-4) = 0
            1x² + 2x + 7 = 0
            
    Enter the values of A, B, C
    0 if not present in equation\n\n"""

def main():
    print(string)

    a=0
    b=0
    c=0

    a = int(input("A = "))
    b = int(input("\nB = "))
    c = int(input("\nC = "))

    d = b*b - 4*a*c

    if(d == 0):
        print("The Determinant of the equation is 0, \nThe roots of the equation are real and equal")
    elif(d > 0):
        print(f"The Determinant of the equation is {d}, \nroots of the equation are real and unequal")
    else:
        print(f"The Determinant of the equation is {d}, \nHence the roots of the equation are imaginary and do not exist")
        stat = false
        return
    
    sqrtd = math.sqrt(d)
    x = round((-b + sqrtd)/(2*a), 2)
    y = round((-b - sqrtd)/(2*a), 2)
    
    print(f"The roots of the equation are {x}, {y}")


if __name__ == "__main__":
    main()