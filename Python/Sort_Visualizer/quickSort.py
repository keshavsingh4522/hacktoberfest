import time


def partition(data, head, tail, drawData, timeSpeed):
    border = head
    pivot = data[tail]
    drawData(data, getColorArray(len(data), head, tail, border, border))
    time.sleep(timeSpeed)
    for j in range(head, tail):
        if data[j] < pivot:
            drawData(data, getColorArray(
                len(data), head, tail, border, j, True))
            time.sleep(timeSpeed)

            data[border], data[j] = data[j], data[border]
            border += 1

        drawData(data, getColorArray(len(data), head, tail, border, j))
        time.sleep(timeSpeed)
    # swap pivot with border value
    drawData(data, getColorArray(len(data), head, tail, border, tail, True))
    time.sleep(timeSpeed)
    data[border], data[tail] = data[tail], data[border]
    return border


def quicksort_Alg(data, head, tail, drawData, timeSpeed):
    if head < tail:
        partitionIdx = partition(data, head, tail, drawData, timeSpeed)
        # LEFT PARTITION
        quicksort_Alg(data, head, partitionIdx-1, drawData, timeSpeed)
        # RIGHT PARTITION
        quicksort_Alg(data, partitionIdx+1, tail, drawData, timeSpeed)


def getColorArray(dataLen, head, tail, border, currIdx, isSwaping=False):
    colorArray = []
    for i in range(dataLen):
        # base coloring
        if i >= head and i <= tail:
            colorArray.append('gray')
        else:
            colorArray.append('pink')
        if i == tail:
            colorArray[i] = 'blue'
        elif i == border:
            colorArray[i] = 'red'
        elif i == currIdx:
            colorArray[i] = 'yellow'
        if isSwaping:
            if i == border or i == currIdx:
                colorArray[i] = 'green'
    return colorArray
