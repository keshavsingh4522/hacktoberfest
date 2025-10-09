# Python program to demonstrate stack implementation using list
 
 
stack = []
 
# append() function to push element in the stack
stack.append('x')
stack.append('y')
stack.append('z')
 
print('Initial stack')
print(stack)
 
# pop() fucntion to pop element from stack
print('\nElements poped from stack:')
print(stack.pop())
print(stack.pop())
print(stack.pop())
 
print('\nStack after elements are poped:')
print(stack)
