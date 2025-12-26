combSort(array, n) // n is the size of array  
  gap = n // Initialize gap size equal to the size of array  
  shrink = 1.3 // gap shrink factor  
  swapped = true  
while (gap ! = 1 || swapped = true)  
    gap = floor(gap/1.3);  
    if gap ≤ 1  
        gap = 1  
    end if  
    swapped = false   
  
    for every element range from 0 to n-gap, do the following -  
            if array[i] > array[i+gap]  
        swap(array[i], array[i+gap])  
        swapped = true  
            end if  
    end for loop  
end while loop  
end combSort  
