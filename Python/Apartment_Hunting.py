
# Approach 01
# O(b^2*r) time | O(b) space - where b is the number of blocks and r is the number of requirements
def appartmentHunting(blocks, reqs):
    maxDistanceAtBlocks = [float('-inf') for block in blocks]
    for i in range(len(blocks)):
        for req in reqs:
            closestReqDistance = float('inf')
            for j in range(len(blocks)):
                if blocks[j][req]:
                    closestReqDistance = min(closestReqDistance, distanceBetween(i, j))
            maxDistanceAtBlocks[i] = max(maxDistanceAtBlocks[i], closestReqDistance)
    return getIndexAtMinValue(maxDistanceAtBlocks)


def distanceBetween(i, j):
    return abs(i - j)


def getIndexAtMinValue(array):
    idxAtMinValue = 0
    minValue = float('inf')
    for i in range(len(array)):
        currentValue = array[i]
        if currentValue < minValue:
            idxAtMinValue = i
            minValue = currentValue
    return idxAtMinValue


# Approach 02
# O(br) time | O(br) space - where b is the number of blocks and r is the number of requirements
#TODO:  Write the code