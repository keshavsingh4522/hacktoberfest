import heapq

def dijkstra(graph, start):
    # Initialize distances to all nodes as infinity except the start node.
    distances = {node: float('inf') for node in graph}
    distances[start] = 0

    # Priority queue to keep track of the nodes to visit.
    priority_queue = [(0, start)]

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        # Ignore nodes that have been visited already with shorter distances.
        if current_distance > distances[current_node]:
            continue

        # Explore neighbors of the current node.
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight

            # If a shorter path is found to the neighbor, update the distance.
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

# Example usage:
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

start_node = 'A'
shortest_distances = dijkstra(graph, start_node)
print("Shortest distances from", start_node, "to each node:")
for node, distance in shortest_distances.items():
    print(node, "-", distance)
