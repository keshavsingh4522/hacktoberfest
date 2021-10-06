# SNAKE GAME USING PYTHON AND PYGAME by SANKET

# imports of different modules
import pygame, sys, random, time
check_errors = pygame.init()
# Here first we will check if the pygame successfully Initialized?

if check_errors[1] > 0:
    print("(!) had {0} initializing errors, exiting....".format(check_errors[1]))
    sys.exit(-1)
else:
    print("(!) PyGame Initialized Successfully!!!")


# Play Surface
playSurface = pygame.display.set_mode((720, 460)) # To set the console window where game will run, the set_mode expects a tupple having dimensions of the console
pygame.display.set_caption('!!! SNAKE GAME !!!') # To set the Upper heading of the game console window


#Colors
# The color method expects three parameters r,g,b combination to give the color
red = pygame.Color(255, 0 ,0) #red color-gameover
green = pygame.Color(0, 255, 0) #green-snake
black = pygame.Color(0, 0, 0) #black-score
white = pygame.Color(255, 255, 255) #white-screen
brown = pygame.Color(165, 42, 42) #brown-food


# fps controller
fpsController = pygame.time.Clock()

# important varibles for the gameover
snakePos = [100, 50] #initial coordinate of the snake head
snakeBody = [[100, 50], [90, 50], [80, 50]] #snake snakeBody
foodPos = [random.randrange(1,72)*10,random.randrange(1,46)*10] #random food positioning
foodSpawn = True
direction = 'RIGHT'
changeTo = direction
score = 0
level = 15
initscore = 0

# Game Over function
def gameOver():
    myFont = pygame.font.SysFont('monaco', 72) #choose font name and size
    GOsurf = myFont.render(' GAME OVER !!!', True, red) # this is the surface where game over will display having 3 args : the message, antialiasing,and Color
    GOrect = GOsurf.get_rect() #to get rect coordinates of the game over text surface
    GOrect.midtop = (360, 15)
    playSurface.blit(GOsurf, GOrect) # bind the gameover text to the main surface
    showScore(0)
    pygame.display.flip() # to set the fps
    time.sleep(5)
    pygame.quit() # exit game window
    sys.exit() # exit cmd console

def showScore(choice=1):
    sFont = pygame.font.SysFont('monaco', 42) #choose font name and size
    Ssurf = sFont.render('SCORE : {0}'.format(score), True, black) # this is the surface where game over will display having 3 args : the message, antialiasing,and Color
    Srect = Ssurf.get_rect() #to get rect coordinates of the game over text surface
    if choice == 1:
        Srect.midtop = (80, 10)
    else:
        Srect.midtop = (360, 120)

    playSurface.blit(Ssurf, Srect) # bind the gameover text to the main surface
    pygame.display.flip() # to set the fps


# Main Logic Of The GAME
while True:
    for event in pygame.event.get(): # accepts the event
        if event.type == pygame.QUIT: # quit event
            pygame.quit()
            sys.exit()
        elif event.type == pygame.KEYDOWN: # when keyboard key is pressed
            if event.key == pygame.K_RIGHT or event.key == ord('d'): # Right Move
                changeTo = 'RIGHT'
            if event.key == pygame.K_LEFT or event.key == ord('a'): # Left Move
                changeTo = 'LEFT'
            if event.key == pygame.K_UP or event.key == ord('w'): # Up Move
                changeTo = 'UP'
            if event.key == pygame.K_DOWN or event.key == ord('s'): # Down Move
                changeTo = 'DOWN'
            if event.key == pygame.K_ESCAPE:
                pygame.event.post(pygame.event.Event(pygame.QUIT))  # post function first creates a event and inside it we emit a quit event

    # validation of direction
    if changeTo == 'LEFT' and not direction =='RIGHT':
        direction = 'LEFT'
    if changeTo == 'RIGHT' and not direction =='LEFT':
        direction = 'RIGHT'
    if changeTo == 'UP' and not direction =='DOWN':
        direction = 'UP'
    if changeTo == 'DOWN' and not direction =='UP':
        direction = 'DOWN'

    # Value change after direction change
    if direction == 'RIGHT':
        snakePos[0] += 10
    if direction == 'LEFT':
        snakePos[0] -= 10
    if direction == 'UP':
        snakePos[1] -= 10
    if direction == 'DOWN':
        snakePos[1] += 10

    # Snake Body Mechanism
    snakeBody.insert(0, list(snakePos))
    if snakePos[0] == foodPos[0] and snakePos[1] == foodPos[1]:
        score += 1
        foodSpawn = False
    else:
        snakeBody.pop()
    # food spawn
    if foodSpawn == False:
        foodPos = [random.randrange(1,72)*10,random.randrange(1,46)*10]
    foodSpawn = True
    playSurface.fill(white)
    for pos in snakeBody:
        pygame.draw.rect(playSurface, green, pygame.Rect(pos[0],pos[1],10,10))
    pygame.draw.rect(playSurface,brown,pygame.Rect(foodPos[0],foodPos[1],10,10))

    # Boundary Condition
    if snakePos[0] > 710 or snakePos[0] < 0:
        gameOver()
    if snakePos[1] > 450 or snakePos[1] < 0:
        gameOver()

    # Self Body Collision
    for block in snakeBody[1:]:
        if snakePos[0] == block[0] and snakePos[1] == block[1]:
            gameOver()

    showScore() # To show the score
    # FPS CONTROL
    pygame.display.flip()
    #pygame.display.update()
    if score == initscore+5:
        level+=5
        initscore = score
    fpsController.tick(level)
