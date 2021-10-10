import pygame
import math
from queue import PriorityQueue

WIDTH = 700
WIN = pygame.display.set_mode((WIDTH, WIDTH))
pygame.display.set_caption("A* Path Finding Algorithm")


# Different color codes of the nodes in the grid
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
YELLOW = (255, 255, 0)
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
PURPLE = (128, 0, 128)
ORANGE = (255, 165, 0)
GREY = (128, 128, 128)
TURQUOISE = (64, 224, 208)

# We will define a class for every single node, or cubes in the grid

# Every cube will keep track of its
# 1. x and y co-ordinate
# 2. Track its color, as colors are important and we move our algorithm by figuring
#    if we reached the end node
# We keep the absolute x and y value, as we need a absolute distance in case of A*


class Node:
    def __init__(self, row, col, width, total_row):
        self.row = row        # Current row and col of the node
        self.col = col
        self.width = width
        self.x = row * width  # This way we calculate the absoulute co-ordinate
        self.y = col * width
        self.color = WHITE    # Initially all the nodes are white
        self.neighbors = []    # Keep track of all the neighbor of the current node
        self.total_row = total_row

    # returns the present co-ordinates of the current node
    def get_pos(self):
        return self.row, self.col

    # to check if we already visited the current node
    # As said earlier, we will check if it is visited if the color is RED
    def is_visited(self):
        return self.color == RED

    # to check the nodes which are reachable from the current node
    # We represent these nodes by GREEN
    def is_reachable(self):
        return self.color == GREEN

    # to represent the barrier in the grid, we will use a BLACK color
    def is_barrier(self):
        return self.color == BLACK

    # start node is defined with an ORANGE color
    def is_start(self):
        return self.color == ORANGE

    # end node is defined by PURPLE color
    def is_end(self):
        return self.color == TURQUOISE

    # to reset the color of current node
    def reset(self):
        self.color = WHITE

    # Now all the methods to make a particular node the different states describes above
    def make_visited(self):
        self.color = RED

    def make_reachable(self):
        self.color = GREEN

    def make_barrier(self):
        self.color = BLACK

    def make_start(self):
        self.color = ORANGE

    def make_end(self):
        self.color = TURQUOISE

    # We will show the actual path from start to end with purple nodes
    def make_path(self):
        self.color = BLUE

    # Method to draw on rectangle on the grid of a particular color, on the window
    # win, then we give the rectangle to draw x,y co-ordinate as well as width and height
    # in our case, width is same as height

    def draw(self, win):
        pygame.draw.rect(
            win, self.color, (self.x, self.y, self.width, self.width))

    # We will update the neighbor only if there exists a grid node and it is not a neighbor
    def update_neighbor(self, grid):
        self.neighbors = []

        # DOWN
        if self.row < self.total_row - 1 and not grid[self.row + 1][self.col].is_barrier():
            self.neighbors.append(grid[self.row + 1][self.col])

        # UP
        if self.row > 0 and not grid[self.row - 1][self.col].is_barrier():  # UP
            self.neighbors.append(grid[self.row - 1][self.col])

        if self.col < self.total_row - 1 and not grid[self.row][self.col + 1].is_barrier():
            self.neighbors.append(grid[self.row][self.col + 1])

        if self.col > 0 and not grid[self.row][self.col - 1].is_barrier():  # LEFT
            self.neighbors.append(grid[self.row][self.col - 1])


# To compare the 2 nodes together we will define this method


    def __lt__(self, other):
        return False

# A* algorithm uses a heuristic function apart from normal edge distances, and this is how
# it is better than dijsktra, so heuristic function can be thought as the actual distance
# between the x and y co-ordinates of the nodes, hence we calculate the sum of actual distance
# and the sum of edge distance to calculate which value to pop from the priority queue


# Here we will call this heuristic distance absolute_dist, but actually we will be using
# abs(x1 - x2) + abs(y1 - y2), we call this the manhattan distance
def absolute_dist(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return abs(x1 - x2) + abs(y1 - y2)


# This will be backtracking from the end node to start node
def reconstruct_path(came_from, current, draw):
    while current in came_from:
        current = came_from[current]
        current.make_path()
        draw()


# The A* Algorithm
def astar_algorithm(draw, grid, start, end):
    count = 0
    open_set = PriorityQueue()
    # initially the total distance is 0, and we are keeping count of nodes to break ties if
    # two whose distances are same are encountered, we will consider the one who came first
    open_set.put((0, count, start))

    # this will keep track of the parent node of the current node
    came_from = {}

    # g_score is the edge distance between two nodes
    g_score = {node: float("inf") for row in grid for node in row}
    g_score[start] = 0

    # f_score is the total distance of g_score + absolute_distance
    f_score = {node: float("inf") for row in grid for node in row}

    # absolute_distance from start to the end node
    f_score[start] = absolute_dist(start.get_pos(), end.get_pos())

    # keeps track of all the items in the priority queue
    open_set_hash = {start}

    while not open_set.empty():

        # To let the user quit the app while its running
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()

        # the open set keeps 3 things, f_score, count of nodes and the nodes,
        # we need only the node, hence 2 and we pop from the queue
        current = open_set.get()[2]

        # then we remove the current node from the queue
        open_set_hash.remove(current)

        # we found the end node and then reconstruct the path from end to start
        if current == end:
            reconstruct_path(came_from, end, draw)
            # to make sure we dont color over the end node
            end.make_end()
            start.make_start()
            return True

        # we explore the neighbors of the current node
        for neighbor in current.neighbors:
            # we are considering that the edge weights of the nodes are just 1
            temp_g_score = g_score[current] + 1

            # if we found a better distance
            if temp_g_score < g_score[neighbor]:

                # keeping track of the parent node of the current node
                came_from[neighbor] = current

                # updating the g_score and the f_score
                g_score[neighbor] = temp_g_score
                f_score[neighbor] = temp_g_score + \
                    absolute_dist(neighbor.get_pos(), end.get_pos())

                # check if we already has the current node in queue
                if neighbor not in open_set_hash:
                    # increase the no. of nodes we found
                    count += 1

                    # as it was not in queue, we put into the queue
                    open_set.put((f_score[neighbor], count, neighbor))
                    open_set_hash.add(neighbor)

                    # now we have to try the paths from the neighbors of the current node
                    # so we make them open
                    neighbor.make_reachable()

        draw()

        # if the current node is not start node, we can color it red as in already visited
        # so it won't be added in the queue
        if current != start:
            current.make_visited()

    # if we did not find the path
    return False


# Dijsktra's algorithm
def dijsktra(draw, grid, start, end):
    count = 0
    open_set = PriorityQueue()

    # initially the total distance is 0, and we are keeping count of nodes to break ties if
    # two whose distances are same are encountered, we will consider the one who came first
    open_set.put((0, count, start))

    # this will keep track of the parent node of the current node
    came_from = {}

    # f_score is the total distance of g_score + absolute_distance
    f_score = {node: float("inf") for row in grid for node in row}

    # absolute_distance from start to the end node
    f_score[start] = 0

    # keeps track of all the items in the priority queue
    open_set_hash = {start}

    while not open_set.empty():

        # To let the user quit the app while its running
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()

        # the open set keeps 3 things, f_score, count of nodes and the nodes,
        # we need only the node, hence 2 and we pop from the queue
        current = open_set.get()[2]

        # then we remove the current node from the queue
        open_set_hash.remove(current)

        # we found the end node and then reconstruct the path from end to start
        if current == end:
            reconstruct_path(came_from, end, draw)
            # to make sure we dont color over the end node
            end.make_end()
            start.make_start()
            return True

        # we explore the neighbors of the current node
        for neighbor in current.neighbors:

            # we are considering that the edge weights of the nodes are just 1
            temp_f_score = f_score[current] + 1

            # if we found a better distance
            if temp_f_score < f_score[neighbor]:

                # keeping track of the parent node of the current node
                came_from[neighbor] = current

                # updating the g_score and the f_score
                f_score[neighbor] = temp_f_score

                # check if we already has the current node in queue
                if neighbor not in open_set_hash:
                    # increase the no. of nodes we found
                    count += 1

                    # as it was not in queue, we put into the queue
                    open_set.put((f_score[neighbor], count, neighbor))
                    open_set_hash.add(neighbor)

                    # now we have to try the paths from the neighbors of the current node
                    # so we make them open
                    neighbor.make_reachable()

        draw()

        # if the current node is not start node, we can color it red as in already visited
        # so it won't be added in the queue
        if current != start:
            current.make_visited()

    # if we did not find the path
    return False


# We need to make a grid, for that we will make a list of rows number of lists and for each
# we will append the nodes
def make_grid(rows, width):
    grid = []
    # This will be the gap between each of the columns, or the length of each cube
    # width is the length of the whole window, hence we do integer division
    gap = width // rows
    for i in range(rows):
        grid.append([])
        for j in range(rows):
            node = Node(i, j, gap, rows)
            grid[i].append(node)

    return grid

# Now we will draw the actual grid, instead of drawing individual cubes, we can draw
# vertical and horizontal lines


def draw_grid(win, rows, width):
    gap = width // rows
    for i in range(rows):
        # This draws the horizontal lines in the win window of the color GREY, the two arguments
        # in the functions are the (start point), (end point)
        #     (start_x, start_y), (end_x, end_y)
        pygame.draw.line(win, GREY, (0, i * gap), (width, i * gap))
        for j in range(rows):
            pygame.draw.line(win, GREY, (j * gap, 0), (j * gap, width))


# This function draws the different colors on the window and tell the pygame to update
# the screen when something new is drawn
def draw(win, grid, rows, width):

    # First we will fill the screen with white
    win.fill(WHITE)

    # Now we will draw the nodes of their own specific colors in the entire grid
    for row in grid:
        for node in row:
            node.draw(win)

    # the order is important here,
    # 1. The screen is filled with WHITE
    # 2. all the nodes are drawn with particular colors
    # 3. now we will draw grid line on top of those nodes
    draw_grid(win, rows, width)

    # Now we will update the screen, it will update every time we want to change something
    pygame.display.update()


# This function will define the cursor x and y positions
def get_clicked_pos(mouse_pos, rows, width):
    gap = width // rows
    y, x = mouse_pos

    # This pin points the location to of the pointed node/cube
    row = y // gap
    col = x // gap

    return row, col


# # An intro screen
# def game_intro(win, width):
#     intro = True
#     while intro:
#         for event in pygame.event.get():
#             if event.type == pygame.QUIT:
#                 pygame.quit()
#                 quit()

#     win.fill(WHITE)
#     largeText = pygame.font.Font('Arial', 155)
#     textSurf, textRect = text_objects("test", largeText)
#     textRect.centre = ((width/2), (width/2))
#     win.blit(textSurf, textRect)
#     pygame.display.update()
#     clock.tick(15)

# The main function


def main(win, width):
    ROWS = 50
    grid = make_grid(ROWS, width)

    # Start and end position
    start = None
    end = None

    # taking input for Dijsktra vs A*
    d = False
    a = False

    # if the app is running
    run = True

    while run:

        # We will draw the grid
        draw(win, grid, ROWS, width)

        for events in pygame.event.get():

            # If we quit the application
            if events.type == pygame.QUIT:
                run = False

            # Now we will look for the input from the user
            # We take 3 inputs, left to make barriers and start and end pos, space to start the algorithm
            if pygame.mouse.get_pressed()[0]:  # LEFT
                pos = pygame.mouse.get_pos()   # Gets the position of mouse on screen
                row, col = get_clicked_pos(pos, ROWS, width)
                node = grid[row][col]   # we will draw the node on the grid

                # If we dont have a start or end pos, we need to make them first before executing further
                if not start and node != end:
                    start = node
                    start.make_start()

                elif not end and node != start:
                    end = node
                    end.make_end()

                # Since user can set 3 types of node, start , end and barrier
                # if we already have start and end then rest of clicks are barriers
                elif node != end and node != start:
                    node.make_barrier()

            # Right mouse button resets the nodes and we can assign it elsewhere
            elif pygame.mouse.get_pressed()[2]:  # RIGHT
                pos = pygame.mouse.get_pos()   # Gets the position of mouse on screen
                row, col = get_clicked_pos(pos, ROWS, width)
                node = grid[row][col]   # we will draw the node on the grid
                node.reset()

                # Reset the start and end if we right click on them
                if node == start:
                    start = None
                elif node == end:
                    end = None

            # Now if we click space on keyboard, the algorithm should run
            if events.type == pygame.KEYDOWN:
                if events.key == pygame.K_SPACE and start and end:
                    # We will update the neighbors of every node visited
                    for row in grid:
                        for node in row:
                            node.update_neighbor(grid)

                    print("Enter 1. Dijsktra")
                    print("Enter 2. A*")
                    a = input("Enter your choice :")

                    a = int(a)

                    # We updated the neighbors and now we will run the algorithm
                    # lamda is anonymous function
                    if a == 1:
                        dijsktra(lambda: draw(win, grid, ROWS, width),
                                 grid, start, end)
                    elif a == 2:
                        astar_algorithm(lambda: draw(win, grid, ROWS, width),
                                        grid, start, end)

                # we can clear the entire screen to start from scratch
                if events.key == pygame.K_c:
                    start = None
                    end = None
                    grid = make_grid(ROWS, width)

    pygame.quit()


main(WIN, WIDTH)
