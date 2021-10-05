import time


def apply_merge(arr, l, mid, r, drawData, timeSpeed):
  # Draw bar
    drawData(arr, getColor(len(arr), l, mid, r))
    time.sleep(timeSpeed)

    left_arr = arr[l:mid+1]
    right_arr = arr[mid+1:r+1]
    l_indx = r_indx = 0
    for arr_indx in range(l, r+1):
        if(l_indx < len(left_arr) and r_indx < len(right_arr)):
            if(left_arr[l_indx] <= right_arr[r_indx]):
                arr[arr_indx] = left_arr[l_indx]
                l_indx += 1
            else:
                arr[arr_indx] = right_arr[r_indx]
                r_indx += 1
        elif(l_indx < len(left_arr)):
            arr[arr_indx] = left_arr[l_indx]
            l_indx += 1
        else:
            arr[arr_indx] = right_arr[r_indx]
            r_indx += 1
    # Draw bar
    drawData(arr, ['red' if x >= l and x <=
                   r else 'pink' for x in range(len(arr))])
    time.sleep(timeSpeed)


def merge(arr, l, r, drawData, timeSpeed):
    if(l < r):
        mid = (l+r)//2
        merge(arr, l,  mid, drawData, timeSpeed)
        merge(arr, mid+1, r, drawData, timeSpeed)
        apply_merge(arr, l, mid, r, drawData, timeSpeed)


def getColor(length, l, mid, r):
    colors = []
    for i in range(length):
        if(i >= l and i <= r):
            if(i >= l and i <= mid):
                colors.append("blue")
            else:
                colors.append("red")
        else:
            colors.append("pink")
    return colors


def mergesort_Alg(arr, drawData, timeSpeed):
    merge(arr, 0, len(arr)-1, drawData, timeSpeed)
