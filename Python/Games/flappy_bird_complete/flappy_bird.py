import pygame
import sys
import random


def draw_floor():
    screen.blit(floor_surface, (floor_x_pos, 435))
    screen.blit(floor_surface, (floor_x_pos+280, 435))


def create_pipe():
    random_pipe_pos = random.choice(pipe_height)
    bottom_pipe = pipe_surface.get_rect(midtop=(400, random_pipe_pos))
    top_pipe = pipe_surface.get_rect(midbottom=(400, random_pipe_pos-200))
    return bottom_pipe, top_pipe


def move_pipes(pipes):
    for pipe in pipes:
        pipe.centerx -= 5
    return pipes


def draw_pipes(pipes):
    for pipe in pipes:
        if pipe.bottom >= 435:
            screen.blit(pipe_surface, pipe)
        else:
            flip_pipe = pygame.transform.flip(pipe_surface, False, True)
            screen.blit(flip_pipe, pipe)


def check_collision(pipes):
    for pipe in pipes:
        if bird_rect.colliderect(pipe):
            death_sound.play()
            return False

    if bird_rect.bottom >= 445 or bird_rect.bottom <= 0:
        return False

    else:
        return True


def rotate_bird(bird):
    new_bird = pygame.transform.rotozoom(bird, -bird_movement * 3, 1)
    return new_bird


def bird_animation():
    new_bird = bird_frames[bird_index]
    new_bird_rect = new_bird.get_rect(center = (100, bird_rect.centery))
    return new_bird, new_bird_rect


def update_score(score, high_score):
    if score > high_score:
        high_score = score
    return high_score


def score_display(game_state):
    if game_state == "main_game":
        score_surface = game_font.render(f"Score: {int(score)}", True, (255, 255, 255))
        score_rect = score_surface.get_rect(center=(140, 50))
        screen.blit(score_surface, score_rect)

    elif game_state == "game_over":
        score_surface = game_font.render(f"Score: {int(score)}", True, (255, 255, 255))
        score_rect = score_surface.get_rect(center=(140, 50))
        screen.blit(score_surface, score_rect)

        high_score_surface = game_font.render(f"High Score: {int(high_score)}", True, (255, 255, 255))
        high_score_rect = high_score_surface.get_rect(center=(140, 415))
        screen.blit(high_score_surface, high_score_rect)


pygame.mixer.pre_init(frequency=44100, size=16, channels=1, buffer=512)
pygame.init()
screen = pygame.display.set_mode((280, 512))
clock = pygame.time.Clock()
game_font = pygame.font.Font("04B_19.ttf", 20)

# Game Variables
gravity = 0.40
bird_movement = 0.00
game_active = True
score = 0
high_score = 0

bg_surface = pygame.image.load("assets/sprites/background-day.png").convert()

game_over = pygame.image.load("assets/sprites/message.png").convert_alpha()
game_over_rect = game_over.get_rect(center=(140, 256))

floor_surface = pygame.image.load("assets/sprites/base.png").convert()
floor_x_pos = 0

bird_upflap = pygame.image.load("assets/sprites/bluebird-upflap.png").convert_alpha()
bird_midflap = pygame.image.load("assets/sprites/bluebird-midflap.png").convert_alpha()
bird_downflap = pygame.image.load("assets/sprites/bluebird-downflap.png").convert_alpha()
bird_frames = [bird_downflap, bird_midflap, bird_downflap]
bird_index = 0
bird_surface = bird_frames[bird_index]
bird_rect = bird_surface.get_rect(center=(50, 256))

# Sounds
flap_sound = pygame.mixer.Sound("assets/audio/wing.wav")
death_sound = pygame.mixer.Sound("assets/audio/hit.wav")

BIRDFLAP = pygame.USEREVENT + 1
pygame.time.set_timer(BIRDFLAP, 50)


pipe_surface = pygame.image.load("assets/sprites/pipe-green.png").convert()
pipe_list = []
SPAWNPIPE = pygame.USEREVENT
pygame.time.set_timer(SPAWNPIPE, 1200)


while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                bird_movement = 0
                bird_movement -= 9
                flap_sound.play()

        if event.type == SPAWNPIPE:
            pipe_list.extend(create_pipe())

        if event.type == BIRDFLAP:
            if bird_index < 2:
                bird_index += 1
            else:
                bird_index = 0
            bird_surface, bird_rect = bird_animation()

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and game_active is False:
                game_active = True
                pipe_list.clear()
                bird_rect.center = (50, 256)
                bird_movement = 0
                score = 0

    screen.blit(bg_surface, (0, 0))

    if game_active:
        # Bird
        rotated_bird = rotate_bird(bird_surface)
        bird_movement += gravity
        bird_rect.centery += int(bird_movement)
        screen.blit(rotated_bird, bird_rect)
        game_active = check_collision(pipe_list)

        # Pipe
        pipe_list = move_pipes(pipe_list)
        draw_pipes(pipe_list)
        pipe_height = [400, 250, 470]

        score += 0.1
        score_display("main_game")

    else:
        screen.blit(game_over, game_over_rect)
        high_score = update_score(score, high_score)
        score_display("game_over")

    # Floor
    floor_x_pos -= 2
    draw_floor()
    if floor_x_pos <= -280:
        floor_x_pos = 0

    pygame.display.update()
    clock.tick(60)
