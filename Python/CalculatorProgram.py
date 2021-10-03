firstnumber = int(input("Enter the first number: "))
secondnumber = int(input("Enter the second number: "))
operator = input("Enter the operator(+,-,/,//,*,**,%): ")
if(operator=='+'):
    print("Addition: ")
    print(firstnumber,"+",secondnumber,"=",firstnumber+secondnumber)
elif(operator=='-'):
    print("Subtraction: ")
    print(firstnumber,"-",secondnumber,"=",firstnumber-secondnumber)
elif(operator=='*'):
    print("Multiplication: ")
    print(firstnumber,"*",secondnumber,"=",firstnumber*secondnumber)
elif(operator=='/'):
    print("Division: ")
    print(firstnumber,"/",secondnumber,"=",firstnumber/secondnumber)
elif(operator=='//'):
    print("Floor Division: ")
    print(firstnumber,"//",secondnumber,"=",firstnumber//secondnumber)
elif(operator=='**'):
    print("Exponential: ")
    print(firstnumber,"^",secondnumber,"=",firstnumber**secondnumber)
elif(operator=='%'):
    print("Modulus: ")
    print(firstnumber,"%",secondnumber,"=",firstnumber%secondnumber)
