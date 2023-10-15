def is_leap_year(year):
    if(year%4 == 0 and year%100 !=0) or (year%400 ==0):
        return True
    else:
        return False

year=int(input("Enter the year which has to be checked for"))
if is_leap_year(year):
    print(year,"is a Leap Year.")

else:
    print(year,"is not a Leap Year.")

    
