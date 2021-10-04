from random import randint
 
 
def swap(A, i, j):
 
    temp = A[i]
    A[i] = A[j]
    A[j] = temp
 
 
# Partition using Lomuto partition scheme
def partition(A, left, right, pIndex):
 
    # Pick `pIndex` as a pivot from the list
    pivot = A[pIndex]
 
    # Move pivot to end
    swap(A, pIndex, right)
 
    # elements less than the pivot will be pushed to the left of `pIndex`;
    # elements more than the pivot will be pushed to the right of `pIndex`;
    # equal elements can go either way
    pIndex = left
 
    # each time we find an element less than or equal to the pivot, `pIndex`
    # is incremented, and that element would be placed before the pivot.
    for i in range(left, right):
        if A[i] <= pivot:
            swap(A, i, pIndex)
            pIndex = pIndex + 1
 
    # Move pivot to its place
    swap(A, pIndex, right)
 
    # return `pIndex` (index of the pivot element)
    return pIndex
 
 
# Returns the k'th smallest element in a list within `left…right`
# (i.e., `left <= k <= right`). The search space within the list is
# changing for each round – but the list is still the same size.
# Thus, `k` does not need to be updated with each round.
def quickSelect(A, left, right, k):
 
    # If the list contains only one element, return that element
    if left == right:
        return A[left]
 
    # select `pIndex` between left and right
    pIndex = randint(left, right)
 
    pIndex = partition(A, left, right, pIndex)
 
    # The pivot is in its sorted position
    if k == pIndex:
        return A[k]
 
    # if `k` is less than the pivot index
    elif k < pIndex:
        return quickSelect(A, left, pIndex - 1, k)
 
    # if `k` is more than the pivot index
    else:
        return quickSelect(A, pIndex + 1, right, k)
 
 
if __name__ == '__main__':
 
    A = [7, 4, 6, 3, 9, 1]
    k = 2
 
    print("k'th smallest element is", quickSelect(A, 0, len(A) - 1, k))