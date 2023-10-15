def isPalindrome(s):
    return s == s[::-1]

while True:
    print("1. To check if the string is palindrome \n2. Quit")
    op = int(input("Enter your choice: "))
    if op == 1:
        word = input("Enter the string: ")
        ans = isPalindrome(word)
        if ans:
            print("Yes,the given string is a palindrome")
        else:
            print("No,the given string is not a palindrome")
    elif op == 2:
        break
    else:
        print("Enter a valid option")
