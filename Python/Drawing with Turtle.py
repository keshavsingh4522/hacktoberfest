#Rainbow
import turtle
 
# Creating a turtle screen object
sc = turtle.Screen()
pen = turtle.Turtle()
rad=90
val=-20
col=['violet','indigo','blue','green','yellow','orange','red']
sc.setup(600, 600)
sc.bgcolor('black')
# Setup the turtle features
pen.right(90)
pen.width(10)
pen.speed(7)
pen.goto(val,0)

# Loop to draw 7 semicircles
for i in col:
    pen.color(i)
    pen.circle(rad, -180)
    pen.up()
    val=val-10
    pen.goto(val, 0)
    pen.down()
    pen.right(180)
    rad+=10
turtle.done()

#full circle
import turtle
sc = turtle.Screen()
pen = turtle.Turtle()
rad=90
val=-20
col=['violet','indigo','blue','green','yellow','orange','red']
sc.bgcolor('black')
 
# Setup the turtle features
pen.width(10)
pen.speed(10)
pen.goto(val,0)

# Loop to draw 7 semicircles
for i in col:
    pen.color(i)
    pen.fillcolor(i)
    pen.begin_fill()
    pen.circle(rad)
    pen.down()
    pen.end_fill()
    rad=rad-10
turtle.done()
#Emoji
import turtle
my_pen = turtle.Turtle()

my_pen.color("#ffdd00")
my_pen.begin_fill()
my_pen.circle(100)
my_pen.fillcolor("#ffdd00")
my_pen.end_fill()


my_pen.goto(-40, 100)
my_pen.color("#555555")
my_pen.begin_fill()
my_pen.circle(15)
my_pen.color("#ffffff")
my_pen.end_fill()
my_pen.penup()
my_pen.goto(-40, 110)
my_pen.pendown()
my_pen.color("Black")
my_pen.begin_fill()
my_pen.circle(5)
my_pen.end_fill()
my_pen.penup()

my_pen.goto(32, 100)
my_pen.pendown()
my_pen.color("#555555")
my_pen.begin_fill()
my_pen.circle(15)
my_pen.color("#ffffff")
my_pen.end_fill()
my_pen.penup()
my_pen.goto(32, 110)
my_pen.pendown()
my_pen.color("Black")
my_pen.begin_fill()
my_pen.circle(5)
my_pen.end_fill()
my_pen.penup()

my_pen.goto(0, 60)
my_pen.setposition(0,60)
my_pen.setheading(0)
my_pen.pendown()
my_pen.pensize(10)
my_pen.circle(-60,40)
my_pen.penup()
my_pen.setposition(0,60)
my_pen.setheading(0)
my_pen.pendown()
my_pen.pensize(10)
my_pen.circle(-60,-40)
turtle.done()

my_pen = turtle.Turtle()
my_pen.color("#ffdd00")
my_pen.begin_fill()
my_pen.circle(100)
my_pen.fillcolor("#ffdd00")
my_pen.end_fill()

my_pen.goto(-40, 100)
my_pen.color("#555555")
my_pen.begin_fill()
my_pen.circle(15)
my_pen.color("#ffffff")
my_pen.end_fill()
my_pen.penup()
my_pen.goto(-40, 110)
my_pen.pendown()
my_pen.color("Black")
my_pen.begin_fill()
my_pen.circle(5)
my_pen.end_fill()
my_pen.penup()

my_pen.goto(32, 100)
my_pen.pendown()
my_pen.color("#555555")
my_pen.begin_fill()
my_pen.circle(15)
my_pen.color("#ffffff")
my_pen.end_fill()
my_pen.penup()
my_pen.goto(32, 110)
my_pen.pendown()
my_pen.color("Black")
my_pen.begin_fill()
my_pen.circle(5)
my_pen.end_fill()
my_pen.penup()

my_pen.goto(0, 30)
my_pen.setposition(0,30)
my_pen.setheading(0)
my_pen.pendown()
my_pen.pensize(10)
my_pen.circle(60,70)
my_pen.penup()
my_pen.setposition(0,30)
my_pen.setheading(0)
my_pen.pendown()
my_pen.pensize(10)
my_pen.circle(60,-70)
turtle.done()
