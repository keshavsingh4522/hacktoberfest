import turtle

# Create a turtle object
heart = turtle.Turtle()

# Set the turtle's shape to "turtle" (optional)
heart.shape("turtle")

# Set the turtle's color and fill color
heart.color("red", "red")

# Lift the pen to move to the starting position
heart.penup()

# Move the turtle to the starting position
heart.goto(0, -100)

# Put the pen down to start drawing
heart.pendown()

# Begin filling the shape
heart.begin_fill()

# Draw the left side of the heart
heart.left(140)
heart.forward(224)
for _ in range(200):
    heart.right(1)
    heart.forward(2)

# Draw the right side of the heart
for _ in range(200):
    heart.right(1)
    heart.forward(2)
heart.forward(224)

# End filling the shape
heart.end_fill()

# Hide the turtle when done
heart.hideturtle()

# Close the drawing window when clicked
turtle.exitonclick()
