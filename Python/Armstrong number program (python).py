#armstrong number program
number = int(input("Enter the number: "))
original_number = number
armstrong_number = 0
while number>0:
    remainder = number%10
    armstrong_number = armstrong_number + remainder*remainder*remainder
    number = number//10
if original_number == armstrong_number:
    print(original_number,"is a armstrong number")
else:
    print(original_number,"is not a armstrong number")
