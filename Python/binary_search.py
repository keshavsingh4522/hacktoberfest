def bi_search(list, item):
    low = 0
    high = len(list) - 1
    while low <= high:
        mid = int((low + high) / 2)
        guess = list[mid]
        if guess == item:
            return mid
        if guess > item:
            high = mid - 1
        else:
            low = mid + 1
    return None

lst = []
n = int(input("Enter number of elements : "))
print("Enter elements in ascending/descending order 👇:")
for i in range(0, n):
	ele = int(input())
	lst.append(ele)
print(lst)
pos = int(input("Enter the element whose position you want to know:"))
if pos in lst:
    bis = bi_search (lst, pos) + 1
    print ("Position of", pos, "in lst is", bis)
else:
    print("It does not exist")
