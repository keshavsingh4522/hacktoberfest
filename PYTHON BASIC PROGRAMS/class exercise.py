class Person:
    def __init__(self,name):
        self.name= name


    def talk(self):
        print(f'Hii, I am {self.name}')


person1 = Person("shaibaz")

person1.talk()
bob = Person("Bob smith")
bob.talk()