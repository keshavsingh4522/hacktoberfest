import turtle
triangle_turtle = turtle.Turtle()
triangle_turtle.speed(15)

def triangle():
    triangle_turtle.right(60)
    triangle_turtle.forward(100)
    triangle_turtle.right(120)
    triangle_turtle.forward(100)
    triangle_turtle.right(120)
    triangle_turtle.forward(100)

for count in range(6):
    triangle()
