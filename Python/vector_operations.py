import numpy as np
x = np.array([1,2,3]);
y = np.array([7,8,9]);
#elementwise
sum = x + y
print("sum=",sum)
Subtraction = x - y
print("Subtraction=",Subtraction)
multiplication = x * y
print("multiplication=",multiplication)
division = x / y
print("division=",division)
modulus = x % y
print("modulus=",modulus)
#dot prodcut
dot = np.dot(x,y)
print("dot product = ", dot)
#cross product
a = np.matrix(((1,2),(4,5)))
b = np.matrix(((10,11),(13,14)))
cross = a * b
print("cross product = ", cross)
