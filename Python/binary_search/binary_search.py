
def binary_search(arr:list, low:int, high:int, x:int) -> list:

    if high >= low:
        mid = (high + low) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
        else:
            return binary_search(arr, mid + 1, high, x)
    else:
        return -1
 
arr:list = []
for _ in range(int(input("Enter the max index: "))):
  arr.append(input(f"Enter {_} element: "))

x = input("Enter element to search: ")
 

result = binary_search(arr, 0, len(arr)-1, x)
 
if result != -1:
    print("Element is present at index", str(result))
else:
    print("Element is not present in array")
