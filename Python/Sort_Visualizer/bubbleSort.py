import time


def bubblesort_Alg(arr, drawData, timeSpeed):
    for i in range(len(arr)-1):
        for j in range(len(arr)-1):
            if(arr[j] > arr[j+1]):
                arr[j], arr[j+1] = arr[j+1], arr[j]
                # To draw the bars
                drawData(arr, ['red' if x == j or x == j +
                               1 else 'blue' for x in range(len(arr))])
                time.sleep(timeSpeed)
    drawData(arr, ['red' for i in range(len(arr))])
    return arr
