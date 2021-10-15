maze =  [[1, 0, 0, 0],
		[1, 1, 0, 1],
		[0, 1, 0, 0],
		[1, 1, 1, 1] ]


def print_maze(maze,sol=False):
	print("-------------------------")
	print("-----------MAZE----------")
	print("-------------------------")
	for i in maze:

		if sol:
			for j in i:
				if j==1:
					print(j," ",end="")
				else:
					print("   ",end="")
		else:
			for j in i:
				print(j," ",end="")

		print("")

def is_maze_safe(maze,x,y):
	if(x>=0 and x<len(maze[0]) and y>=0 and y<len(maze) and maze[x][y]==1):
		return True

	return False

def solve_maze_function(maze,x,y,sol_maze):

	if (x == len(maze[0])-1 and y == len(maze)-1 and maze[x][y]==1):
		sol_maze[x][y]=1
		return True

	if is_maze_safe(maze,x,y):

		if(sol_maze[x][y] == 1):
			return False

		sol_maze[x][y] = 1

		if(solve_maze_function(maze, x+1, y, sol_maze) == True):
			return True

		if(solve_maze_function(maze, x, y+1, sol_maze) == True):
			return True

		if(solve_maze_function(maze, x-1, y, sol_maze) == True):
			return True

		if(solve_maze_function(maze, x, y-1, sol_maze) == True):
			return True

		sol_maze[x][y] = 0

		return False

def solve_maze(maze):

	sol_maze = [ [0 for j in range(len(maze[0]))] for i in range(len(maze))]

	if solve_maze_function(maze,0,0,sol_maze) == False:
		print("Solution doesn't exists")
		return False

	print_maze(sol_maze, sol=True)
	return True



if __name__=="__main__":
	print_maze(maze)
	solve_maze(maze)

