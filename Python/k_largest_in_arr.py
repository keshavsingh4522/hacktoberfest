import heapq


# Return k largest elements from an array

# use heaps
def find_k_largest(arr, k):
    heap = []
    for i in range(k):
        heapq.heappush(heap, arr[i])

    heapq.heapify(heap)

    for i in range(k, len(arr)):
        if arr[i] > heap[0]:
            heapq.heappop(heap)
            heapq.heappush(heap, arr[i])
            heapq.heapify(heap)
    return heap


# use sorting
def find_k_largest_in_array(arr, k):
    arr.sort()
    result = []

    for i in range(len(arr) - 1, len(arr) - 1 - k, -1):
        result.append(arr[i])

    return result


def main():
    arr = [1, 23, 12, 9, 30, 2, 50]
    k = 3
    print(find_k_largest_in_array(arr, k))
    print(find_k_largest(arr, k))
    

if __name__ == '__main__':
    main()
