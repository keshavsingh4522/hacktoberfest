import numpy as np
from functools import reduce
import copy
import sys

def calculateColumnRow(datas) :
    sumRow = []
    sumColumn = []
    column = datas.sum(axis=0)
    sumColumn = column.tolist()
    row = datas.sum(axis=1)
    sumRow = row.tolist()
    return sumRow, sumColumn

def getHeuristics(sumRow, sumColumn) :
    result = 0
    for row in sumRow:
        for column in sumColumn:
            result += abs(row - column)
    return result

box = np.array([[9, 3, 6],
                [4, 1, 2],
                [7, 5, 8]])

# box = np.array([[9, 7, 3], [4, 8, 1], [5, 6, 2]])

result = []
minimum = float('inf')
minimumPair = []
minimumBox = []
minimumSumRowColumn = []
compare = 0
count = 0
note = 0

original_stdout = sys.stdout # Save a reference to the original standard output

with open('hasil-hillclimb.txt', 'w') as f:
    sys.stdout = f
    for firstLoop in range(0, len(box)):
        for secondLoop in range(0, len(box[firstLoop])):
            for thirdLoop in range(firstLoop, len(box)):
                for fourthLoop in range(secondLoop + 1 if thirdLoop == firstLoop else 0, len(box[thirdLoop])):
                    
                    newMatrix = copy.deepcopy(box)
                    temporaryMatrix = newMatrix[firstLoop][secondLoop]
                    newMatrix[firstLoop, secondLoop] = newMatrix[thirdLoop][fourthLoop]
                    newMatrix[thirdLoop][fourthLoop] = temporaryMatrix

                    sumRow, sumColumn = calculateColumnRow(newMatrix)
                    sumRowColumn = sumRow + sumColumn

                    heuristics = getHeuristics(sumRow, sumColumn)
                    result.append(heuristics)
                    
                    count += 1
                    
                    # if compare < 5 :
                    print ("\033[1;31;40m" + "Pertukaran ke - " + str(count))
                    print( "\033[1;31;40m" + str(newMatrix[thirdLoop][fourthLoop]) + " -> " + str(newMatrix[firstLoop][secondLoop]) )
                    print ("\033[1;31;40m" + str(newMatrix))
                    print("\033[1;31;40m" + str(sumRow + sumColumn))
                    print("\033[1;31;40m" + str(heuristics) + "\n")
                    compare += 1   
                            
                    if (heuristics < minimum) :
                        note = count
                        minimum = heuristics
                        minimumBox = newMatrix
                        minimumSumRowColumn = sumRowColumn
                        minimumPair = str( str(newMatrix[thirdLoop][fourthLoop]) + " -> " + str(newMatrix[firstLoop][secondLoop]) )

    print("\033[1;32;40m <-------------------- Best Solution -------------------->")
    print ("\033[1;32;40m" + str(minimumPair))
    print ("\033[1;32;40m" + str(minimumBox))
    print ("\033[1;32;40m" + str(minimumSumRowColumn))
    print ("\033[1;32;40m" + str(minimum))
    print("\033[1;32;40m On step : " + str(note))
    print (count)
    sys.stdout = original_stdout
