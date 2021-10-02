import turtle
import winsound
wn = turtle.Screen()
wn.title("Pong by Monu")
wn.bgcolor("black")
wn.setup(width=800, height=600)
wn.tracer(0) #this speed up the game
# 0,0 is at center from there to right here it is 400 and to left as well 400 
# again for height 300 above and 300 below


#Paddle A 
paddle_a = turtle.Turtle()   #turtle object it is
paddle_a.speed(0) #this is not the speed that paddle moves on screen, this the spped of animation what it does is that sets the speed to the maximum possible speed
paddle_a.shape("square")
paddle_a.color("white")
paddle_a.shapesize(stretch_wid=5, stretch_len=1)
paddle_a.penup() #turtles by defination what they do draw a line as they're moving,here we don't need  therefore penup is used;- is Pull the pen up -- no drawing when moving.
paddle_a.goto(-350, 0)

#Paddle B
paddle_b = turtle.Turtle()  
paddle_b.speed(0) 
paddle_b.shape("square")
paddle_b.color("white")
paddle_b.shapesize(stretch_wid=5, stretch_len=1)
paddle_b.penup() 
paddle_b.goto(350, 0)

#Ball
ball = turtle.Turtle()  
ball.speed(0) 
ball.shape("circle")
ball.color("white")
#no stretch
ball.penup() 
ball.goto(0, 0)
ball.dx = 2
ball.dy = -2    
'''this means that everytime ball moves it moves by 2 pixels since here dx is positive it moves right 
and dy is also positive it moves up so it'd be kind of moving up and diagonnally
'''

#Pen
pen = turtle.Turtle()
pen.speed(0)
pen.color("white")
pen.penup() #no line when (pen moves as already stated
pen.hideturtle()
pen.goto(0,260)
pen.write("Player A: 0 Player B: 0",align="center", font=("Courier",24 ,"normal"))
score_a=0
score_b=0

#function
def paddle_a_up():
    y = paddle_a.ycor()    # ycor()it's from turtle module it return y coordinate
    y += 100
    paddle_a.sety(y)

def paddle_a_down():
    y = paddle_a.ycor()    
    y -= 100
    paddle_a.sety(y)


def paddle_b_up():
    y = paddle_b.ycor()    # ycor()it's from turtle module it return y coordinate
    y += 200
    paddle_b.sety(y)

def paddle_b_down():
    y = paddle_b.ycor()    
    y -= 200
    paddle_b.sety(y)

# Keyboard binding
wn.listen()  # listen input from keyboard
wn.onkeypress(paddle_a_up, "w")
wn.onkeypress(paddle_a_down, "s")
wn.onkeypress(paddle_b_up, "Up")
wn.onkeypress(paddle_b_down, "Down")

# main game loop
while True:
    wn.update()

    #Move the ball
    ball.setx(ball.xcor() + ball.dx)  
    ball.sety(ball.ycor() + ball.dy)

#     Border checking
#     """as height is 600 we need to have ball bounce"""
    if ball.ycor() >290:
        ball.sety(290) 
        ball.dy *= -1
        #winsound.PlaySound(".wav", winsound.SND_ASYNC)
    
    elif ball.ycor() <-290:
        ball.sety(-290)
        ball.dy *=-1

    elif ball.xcor() >390:
        ball.goto(0 ,0)
        ball.dx *= -1
        score_a +=1
        pen.clear() #it clears screen but it happens so fast
        pen.write(f"Player A:{score_a}  Player B: {score_b}",align="center", font=("Courier",24 ,"normal"))

    elif ball.xcor() <-390:
        ball.goto(0 ,0)
        ball.dx *= -1
        score_b +=1

    #Paddle and ball collisions 
    if (ball.xcor() > 340 and ball.xcor() <350) and (ball.ycor() < paddle_b.ycor() +50 and ball.ycor() >paddle_b.ycor() -50):
        ball.setx(340)
        ball.dx *= -1

    if (ball.xcor() < -340 and ball.xcor() >-350) and (ball.ycor() < paddle_a.ycor() +50 and ball.ycor() >paddle_a.ycor() -50):
        ball.setx(-340)
        ball.dx *= -1
