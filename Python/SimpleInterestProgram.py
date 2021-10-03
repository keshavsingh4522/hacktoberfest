principal_amount = int(input("Enter the principle amount: "))
interest_rate = float(input("Enter the interest rate: "))
time_period = input("Enter the time period (month or year): ")
if(time_period == "month"):
    month_period = int(input("Enter the month period: "))
    simple_interest = (principal_amount*interest_rate*month_period)/100;
    print("The simple interest for","Rs",principal_amount,"after",month_period,"months","at a rate of",interest_rate,":",simple_interest)
elif(time_period == "year"):
    year_period = int(input("Enter the year period: "))
    simple_interest = (principal_amount*interest_rate*year_period)/100;
    print("The simple interest for","Rs",principal_amount,"after",year_period,"years","at a rate of",interest_rate,":",simple_interest)
