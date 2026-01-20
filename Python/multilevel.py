class Employee:
    print("Amazing")

class Skill:
    print ("data structures") 
    level=2   

class Person(Employee, Skill):
    name="bitel"

p=Person 
print(p.level)    
