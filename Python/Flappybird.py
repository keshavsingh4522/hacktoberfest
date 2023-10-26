import pygame
import random

pygame.init()

# Constants
WIDTH, HEIGHT = 400, 600
BIRD_WIDTH, BIRD_HEIGHT = 50, 50
PIPE_WIDTH = 60
PIPE_GAP = 200
PIPE_VELOCITY = 5
BIRD_VELOCITY = 0

# Colors
WHITE = (255, 255, 255)
BLUE = (0, 0, 255)

# Create the game window
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Flappy Bird")

# Load bird image
bird_image = pygame.image.load("bird.png")
bird_image = pygame.transform.scale(bird_image, (BIRD_WIDTH, BIRD_HEIGHT))

# Load pipe image
pipe_image = pygame.image.load("pipe.png")
pipe_image = pygame.transform.scale(pipe_image, (PIPE_WIDTH, HEIGHT))

# Initialize bird position
bird_x = 50
bird_y = HEIGHT // 2 - BIRD_HEIGHT // 2

# Create pipes
pipes = []
pipe_x = WIDTH
pipe_height = random.randint(100, 400)
pipes.append([pipe_x, pipe_height])

# Score
score = 0

# Game loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                BIRD_VELOCITY = -10

    # Bird movement
    bird_y += BIRD_VELOCITY
    BIRD_VELOCITY += 1

    # Update pipe positions
    for pipe in pipes:
        pipe[0] -= PIPE_VELOCITY

    # Check for collisions
    for pipe in pipes:
        if bird_x + BIRD_WIDTH > pipe[0] and bird_x < pipe[0] + PIPE_WIDTH:
            if bird_y < pipe[1] or bird_y + BIRD_HEIGHT > pipe[1] + PIPE_GAP:
                running = False

    # Remove off-screen pipes and add new ones
    if pipes[0][0] + PIPE_WIDTH < 0:
        pipes.pop(0)
        new_pipe_height = random.randint(100, 400)
        pipes.append([WIDTH, new_pipe_height])
        score += 1

    # Draw everything
    screen.fill(WHITE)
    for pipe in pipes:
        screen.blit(pipe_image, (pipe[0], 0))
        screen.blit(pipe_image, (pipe[0], pipe[1] + PIPE_GAP))
    screen.blit(bird_image, (bird_x, bird_y))

    # Display score
    font = pygame.font.Font(None, 36)
    text = font.render("Score: " + str(score), True, BLUE)
    screen.blit(text, (10, 10))

    pygame.display.update()

# Quit the game
pygame.quit()
