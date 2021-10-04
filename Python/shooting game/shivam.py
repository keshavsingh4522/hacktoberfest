import pygame
import os

WIDTH,HEIGHT = 1080,600
WIN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("GAME!! GAME!! GAME!!")

FPS = 60
VEL = 5
BORDER = pygame.Rect(WIDTH/2-5,0,10,HEIGHT)
BG = pygame.image.load(os.path.join('Assets','space.png'))
spaceship_height, spaceship_width = 55, 40
Spaceship1_Image = pygame.image.load(os.path.join('Assets','spaceship_yellow.png'))
Spaceship1 = pygame.transform.rotate(pygame.transform.scale(Spaceship1_Image, (spaceship_height,spaceship_width)),90)
Spaceship2_Image = pygame.image.load(os.path.join('Assets','spaceship_red.png'))
Spaceship2 = pygame.transform.rotate(pygame.transform.scale(Spaceship2_Image, (spaceship_height,spaceship_width)),270)

def draw_window(first,second):
    WIN.fill((150,225,0))
    pygame.draw.rect(WIN, (0,0,0), BORDER)
    WIN.blit(Spaceship1,(first.x,first.y))
    WIN.blit(Spaceship2,(second.x, second.y))
    pygame.display.update()

def first_handle(keys_pressed, first):
    if keys_pressed[pygame.K_a] and first.x - VEL > 0: #left
        first.x -= VEL
    if keys_pressed[pygame.K_d] and first.x + VEL < 500: #right
        first.x += VEL
    if keys_pressed[pygame.K_w] and first.y - VEL > 0 : #up
        first.y -= VEL
    if keys_pressed[pygame.K_s] and first.y + VEL < 550: #down
        first.y += VEL

def second_handle(keys_pressed, second):
    if keys_pressed[pygame.K_LEFT]  and second.x + VEL > 550: #left
        second.x -= VEL
    if keys_pressed[pygame.K_RIGHT]  and second.x - VEL < 1030: #right
        second.x += VEL
    if keys_pressed[pygame.K_UP]  and second.y - VEL > 0: #up
        second.y -= VEL
    if keys_pressed[pygame.K_DOWN]  and second.y + VEL < 550: #down
        second.y += VEL

def main():
    first = pygame.Rect(100,250,spaceship_height,spaceship_width)
    second = pygame.Rect(600,250,spaceship_height,spaceship_width)
    clock = pygame.time.Clock()
    run = True
    # first_bullets = 
    # second_bullets = 

    while run:
        clock.tick(FPS)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
        if event.type=pygame.KEYDOWN :
            if event.key = pygame.K_LCTRL:

            if event.key = pygame.K_RCTRL:

        keys_pressed = pygame.key.get_pressed()
        first_handle(keys_pressed, first)
        second_handle(keys_pressed, second)
        # if (first.x-5) == (second.x-5):
        #     first.x = 100
        #     second.x = 100
        draw_window(first,second)

    pygame.quit()

if __name__ == "__main__":
    main()
