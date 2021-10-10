import queue


class Graph(object):
    def __init__(self, nVertices):
        self.nVertices = nVertices
        self.adjMatrix = [[0 for i in range(nVertices)]
                          for j in range(nVertices)]

    def addEdge(self, v1, v2):
        self.adjMatrix[v1][v2] = 1
        self.adjMatrix[v2][v1] = 1

    def removeEdge(self, v1, v2):
        if self.containsEdge(v1, v2) is False:
            return
        self.adjMatrix[v1][v2] = 0
        self.adjMatrix[v2][v1] = 0

    def containsEdge(self, v1, v2):
        return True if self.adjMatrix[v1][v2] > 0 else False

    def printGraph(self):
        print("    ", end="")
        for i in range(self.nVertices):
            print(i, end=" ")
        print()
        for i in range(self.nVertices):
            print(i, "|", end=' ')
            for j in range(self.nVertices):
                print(self.adjMatrix[i][j], end=" ")
            print()

    def __dfsHelper(self, sv, visited):
        print(sv, end=" ")
        visited[sv] = True
        for i in range(self.nVertices):
            if (self.adjMatrix[sv][i] > 0 and visited[i] is False):
                self.__dfsHelper(i, visited)

    def dfs(self):
        visited = [False for i in range(self.nVertices)]
        print("DFS:")
        for i in range(self.nVertices):
            if visited[i] is False:
                self.__dfsHelper(i, visited)
        print()

    def __bfsHelper(self, sv, visited):
        q = queue.Queue()
        q.put(sv)
        visited[sv] = True
        while q.empty() is False:
            u = q.get()
            print(u, end=" ")
            for i in range(self.nVertices):
                if self.adjMatrix[u][i] > 0 and visited[i] is False:
                    q.put(i)
                    visited[i] = True

    def bfs(self):
        visited = [False for i in range(self.nVertices)]
        print("BFS:")
        for i in range(self.nVertices):
            if visited[i] is False:
                self.__bfsHelper(i, visited)
        print()

    def __str__(self):
        return str(self.adjMatrix)


graph = Graph(7)
graph.addEdge(0, 1)
graph.addEdge(1, 3)
graph.addEdge(2, 4)
graph.addEdge(2, 3)
graph.addEdge(0, 2)
graph.addEdge(5, 6)
print(graph)
graph.printGraph()
graph.dfs()
graph.bfs()
