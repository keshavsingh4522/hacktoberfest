#palindrome_partition

#Method to check whether the string is palindrome or not
def isPalindrome(string:str, start:int, end:int): 
    while start < end: 
        if string[end] != string[start]: 
            return False
        start += 1
        end -= 1
    return True

#Recursive method to search for all the possible partitions.
def findAllPartitions(allPartitions, subPartitions, initial, n, string):
    if initial >= n:
        x = subPartitions.copy() 
        allPartitions.append(x)
        return

    for i in range(initial, n): 
        if isPalindrome(string, initial, i): 
 
            subPartitions.append(string[initial:i + 1]) 

            findAllPartitions(allPartitions, subPartitions, i + 1, n, string) 

            subPartitions.pop() 

#Method to print all the possible palindrome partitions.
def palindromePartitions(string):
    allPartitions = []
    subPartitions = []

    findAllPartitions(allPartitions, subPartitions, 0, len(string), string)
    
    for i in enumerate(allPartitions):
        for j in enumerate(allPartitions[i[0]]):
            print(allPartitions[i[0]][j[0]], end = " ") 
        print() 

#Take a string input
string = str(input())
palindromePartitions(string) 