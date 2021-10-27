# Create a square with a given size
size = int(input("Enter square size: "))

square = "Invalid square size!"
if size > 1:
    square = ""
    for row in range(size):
        for column in range(size):
            square += "* "
        square += "\n"
print(square)
