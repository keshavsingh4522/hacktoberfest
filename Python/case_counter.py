def case_counter(string: str):
    upper_case = lower_case = 0
    for i in string:
        if i.isupper():
            upper_case += 1
        elif i.islower():
            lower_case +=1
    print("Upcount: " + str(upper_case))
    print("Lower: " +  str(lower_case))

case_counter("Bimal")
