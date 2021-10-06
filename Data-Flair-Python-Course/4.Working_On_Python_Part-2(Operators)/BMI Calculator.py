def bmi_calculator(weight,height):
    results(weight/(height/100)**2)

def results(bmi):
    result="underweight" if bmi<18.5 else "normal weight" if bmi>=18.5 and bmi<=24.9 else "overweight" if bmi>=25 and bmi<=29.9 else "obese"
    print("Your BMI is "+str(round(bmi,1))+"; this is considered "+str(result))
