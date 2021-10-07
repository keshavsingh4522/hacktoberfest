maxN = 10005

# The array to store the
# height of the nodes
height = [0 for i in range(maxN)]

# Adjacency List to store
# the tree
tree = [[] for i in range(maxN)]

# variable to store diameter
# of the tree
diameter = 0

# Function to add edge between
# node u to node v
def addEdge(u, v):

	# add edge from u to v
	tree[u].append(v)
	
	# add edge from v to u
	tree[v].append(u)

def dfs(cur, par):
	global diameter
	
	# Variables to store the height of children
	# of cur node with maximum heights
	max1 = 0
	max2 = 0
	
	# going in the adjacency list of the current node
	for u in tree[cur]:
	
		# if that node equals parent discard it
		if(u == par):
			continue
		
		# calling dfs for child node
		dfs(u, cur)
		
		# calculating height of nodes
		height[cur] = max(height[cur], height[u])
		
		# getting the height of children
		# of cur node with maximum height
		if(height[u] >= max1):
			max2 = max1
			max1 = height[u]
		elif(height[u] > max2):
			max2 = height[u]
	height[cur] += 1
	
	# Diameter of a tree can be calculated as
	# diameter passing through the node
	# diameter doesn't includes the cur node
	diameter = max(diameter, height[cur])
	diameter = max(diameter, max1 + max2 + 1)

# Driver Code
# n is the number of nodes in tree
n = 7

# Adding edges to the tree
addEdge(1, 2)
addEdge(1, 3)
addEdge(1, 4)
addEdge(2, 5)
addEdge(4, 6)
addEdge(4, 7)

# Calling the dfs function to
# calculate the diameter of tree
dfs(1, 0)

print("Diameter of tree is :", diameter - 1)
