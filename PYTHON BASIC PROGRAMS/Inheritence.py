class Mammmal:
    def walk(self):
        print("walk")


class Dog(Mammmal):
    def bark(self):
        print("bark")


class Cat(Mammmal):
    def be_humble(self):
        print("cutyy")

dog1 = Dog()
dog1.walk()
dog1.bark()

cat1 = Cat()
cat1.be_humble()