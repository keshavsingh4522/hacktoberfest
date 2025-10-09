t = int(input())
def quicksort(arr,low,high):
    
    if low>=high:
        return 
    pivot = partition(arr,low,high)
    quicksort(arr,low,pivot-1)
    quicksort(arr,pivot+1,high)

def partition(arr,low,high):
    
    mid = (low+high)//2
    
    temp = arr[high]
    arr[high] = arr[mid]
    arr[mid] = temp
    
    i = low
    for j in range(low,high):
        if arr[j]<=arr[high]:
            temp = arr[j]
            arr[j] = arr[i]
            arr[i] = temp
            i+=1
    #print(i)
    temp = arr[high]
    arr[high] = arr[i]
    arr[i] = temp
    
    return i
    
for i in range(t):       # no of test cases
    n = int(input())     # no of elements in array 
    arr = [int(x) for x in input().split()] #enter array with spaces
    quicksort(arr,0,n-1)       # like 27 3 5 1 8
    print(arr)
