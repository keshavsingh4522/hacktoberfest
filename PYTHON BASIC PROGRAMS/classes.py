class Point:
    def __init__(self,x,y):
        self.x =x
        self.y = y

    def move(self):
        print("move")
    def draw(self):
        print("draw")


point2 = Point(10, 30)
point2.x = 11
print(point2.x)




