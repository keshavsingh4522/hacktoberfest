#Strings Manipulation


# Given an integer, return the integer with reversed digits.
# Note: The integer could be either positive or negative.

def solution(x):
    string = str(x)
    
    if string[0] == '-':
        return int('-'+string[:0:-1])
    else:
        return int(string[::-1])
    
print(solution(-23)) #You can pass any number as a parameter.

print(solution(8765)) #You can pass any number as a parameter.