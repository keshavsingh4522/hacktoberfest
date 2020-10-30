n = 0
fees = 0
while True:
    age1 = input()
    if age1 == '' or n>20:
        break
    age = int(age1)
    if age<=0 or age>120:
        print("Invalid Input")
    elif age<17:
        fees += 200
        n += 1
    elif age<40 and age>=17:
        fees += 400
        n += 1
    elif age>=40:
        fees += 300
        n += 1
print(fees)
