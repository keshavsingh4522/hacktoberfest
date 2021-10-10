class Graph(object):
    def __init__(self, nodes, is_directed=False):
        self.nodes = nodes
        self.adjlist = {}
        self.is_directed = is_directed
        for node in self.nodes:
            self.adjlist[node] = []

    def addEdge(self, u, v):
        self.adjlist[u].append(v)
        if self.is_directed is False:
            self.adjlist[v].append(u)

    def removeEdge(self, u, v):
        if self.containsEdge(u, v) is False:
            return
        self.adjlist[u].remove(v)
        if self.is_directed is False:
            self.adjlist[v].remove(u)

    def containsEdge(self, u, v):
        return True if v in self.adjlist[u] else False

    def print_list(self):
        for node in self.nodes:
            print(node, "->", self.adjlist[node])

    def dfs(self):
        visited = [False for i in range(self.nodes)]
        print("DFS:")

    def __str__(self):
        return str(self.adjlist)


# driver code
nodes = ["A", "B", "C", "D", "E"]
edges = [("A", "B"), ("A", "C"), ("B", "D"),
         ("C", "D"), ("C", "E"), ("D", "E")]

graph = Graph(nodes)  # is_directed=True
for u, v in edges:
    graph.addEdge(u, v)
graph.print_list()
graph.removeEdge("A", "B")
print()
graph.print_list()
print()
print(graph)
