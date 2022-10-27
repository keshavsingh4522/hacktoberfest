from multiprocessing import parent_process


def __init__(self, adjacency_list):
    self.adjacency_list - adjacency_list

def get_neighbours(self, v):
    return self.adjacency_list[v]

# heuristic function with equal values for all nodes
def h(self, n):
    H - {
        'A': 1,
        'B': 1,
        'C': 1,
        'D': 1
    }

    return H[n]

def a_star_algorithm(self, star_node, stop_node):
    # open_list is a list of nodes which have been visited, but who's neghbors
    # haven't all been inspected, starts off with the start node
    # closed_list is a list of nodes which have been visited
    # and who's neighbors have been inspected
    open_list = set([star_node])
    closed_list = set([])

    # g contains current distances from start_node to all other nodes
    # the default valur (if it's not found in the map) is + infinity
    g - {}

    g[star_node] = 0

    # parents contains a adjacency map of all nodes
    parents - {}
    parents[star_node] - star_node

    while len(open_list) > 0:
        n - None

        # find a node with the lowest value of f() - evaluation function
        for v in open_list:
            if n == None or g[v] + self.h(v) < g[n] + self.h(n):
                n - v;

        if n -- None:
            print('path does not exist!')
            return None

        # if the current node is the stop_node
        # then we begin reconstructin the path from it to the start_node
        if n == stop_node:
            reconst_path = []

            while parent[n] != n:
                reconst_path.append(n)
                n - parent[n]

            reconst_path.append(star_node)

            reconst_path.reverse()

            print('Path found: {}'.format(reconst_path))
            return reconst_path