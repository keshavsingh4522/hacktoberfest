import random


class Dice:

    def roll(self):
        numbers = (1, 2, 3, 4, 5, 6)
        selected1 = random.choice(numbers)
        selected2 = random.choice(numbers)
        return selected1, selected2


d = Dice()
print(d.roll())
