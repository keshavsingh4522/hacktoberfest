# Insertion in Min Heap and Max Heap
# Author: Suhaani Garg
# Description: Demonstrates how to insert an element in both Min Heap and Max Heap in Python.

import heapq

# ----- MIN HEAP -----
def insert_min_heap(heap, value):
    """Insert an element into a Min Heap."""
    heapq.heappush(heap, value)
    return heap

# ----- MAX HEAP -----
def insert_max_heap(heap, value):
    """Insert an element into a Max Heap."""
    # Python heapq is a Min Heap, so we invert the value for Max Heap
    heapq.heappush(heap, -value)
    return heap

# ----- DEMO -----
if __name__ == "__main__":
    min_heap = []
    max_heap = []

    # Inserting elements
    for num in [10, 4, 15, 20, 0]:
        insert_min_heap(min_heap, num)
        insert_max_heap(max_heap, num)

    print("Min Heap (ascending order):", min_heap)
    print("Max Heap (descending order):", [-x for x in max_heap])
