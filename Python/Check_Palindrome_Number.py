#Write a program to determine if given number is palindrome or not. Print true if it is palindrome, false otherwise

def isPalindrome(s):
       
    #to change it the string is similar case
    s = s.lower()
    # length of s
    l = len(s)
     
    # if length is less than 2
    if l < 2:
        return True
 
    # If s[0] and s[l-1] are equal
    elif s[0] == s[l - 1]:
        
        # Call is pallindrome form substring(1,l-1)
        return isPalindrome(s[1: l - 1])
 
    else:
        return False
 
# main Code
s = input()
ans = isPalindrome(s)
 
if ans:
    print("true")
 
else:
    print("false")
