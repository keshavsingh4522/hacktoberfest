import pygame
import sys
import random

class Snake():
    def __init__(self):
        self.length = 1
        self.positions = [((screen_width/2), (screen_height/2))]
        self.direction = random.choice([up, down, left, right])
        self.color = (0, 128, 0)
        self.score = 0

    def get_head_position(self):
        return self.positions[0]

    def turn(self, point):
        if self.length > 1 and (point[0]*-1, point[1]*-1) == self.direction:
            return
        else:
            self.direction = point

    def move(self):
        cur = self.get_head_position()
        x,y = self.direction
        new = (((cur[0]+(x*gridsize))%screen_width), (cur[1]+(y*gridsize))%screen_height)
        if len(self.positions) > 2 and new in self.positions[2:]:
            self.reset()
        else:
            self.positions.insert(0,new)
            if len(self.positions) > self.length:
                self.positions.pop()

    def reset(self):
        self.length = 1
        self.positions = [((screen_width/2), (screen_height/2))]
        self.direction = random.choice([up, down, left, right])
        self.score = 0

    def draw(self,surface):
        
        for p in self.positions:
            r = pygame.Rect((p[0], p[1]), (gridsize,gridsize))
            if(p==self.positions[0]):
                pygame.draw.rect(surface,(0, 50, 0),r)
            else:
                pygame.draw.rect(surface, self.color, r)

    def handle_keys(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    self.turn(up)
                elif event.key == pygame.K_DOWN:
                    self.turn(down)
                elif event.key == pygame.K_LEFT:
                    self.turn(left)
                elif event.key == pygame.K_RIGHT:
                    self.turn(right)

class Food():
    def __init__(self):
        self.position = (0,0)
        self.color = (223, 163, 49)
        self.randomize_position()

    def randomize_position(self):
        self.position = (random.randint(0, grid_width-1)*gridsize, random.randint(0, grid_height-1)*gridsize)

    def draw(self, surface):
        r = pygame.Rect((self.position[0], self.position[1]), (gridsize, gridsize))
        pygame.draw.rect(surface, self.color, r)
        pygame.draw.rect(surface, (93, 216, 228), r, 1)

def drawGrid(surface):
    for y in range(0, int(grid_height)):
        for x in range(0, int(grid_width)):
            r = pygame.Rect((x*gridsize, y*gridsize), (gridsize,gridsize))
            pygame.draw.rect(surface,(93,216,228), r)


screen_width = 480
screen_height = 480

gridsize = 20
grid_width = screen_width/gridsize
grid_height = screen_height/gridsize

up = (0,-1)
down = (0,1)
left = (-1,0)
right = (1,0)

def main():
    pygame.init()

    clock = pygame.time.Clock()
    screen = pygame.display.set_mode((screen_width, screen_height), 0, 32)

    surface = pygame.Surface(screen.get_size())
    surface = surface.convert()
    drawGrid(surface)

    snake = Snake()
    food = []
    for i in range(3):
        food.append(Food())
    myfont = pygame.font.SysFont("monospace",16)

    while (True):
        clock.tick(5+snake.length)
        snake.handle_keys()
        drawGrid(surface)
        snake.move()
        for i in food:
            if snake.get_head_position() == i.position:
                snake.length += 1
                snake.score += 1
                i.randomize_position()
            i.draw(surface)
        snake.draw(surface)
        screen.blit(surface, (0,0))
        text = myfont.render("Score {0}".format(snake.score), 1, (0,0,0))
        screen.blit(text, (5,10))
        pygame.display.update()

main()