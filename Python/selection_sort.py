
A = [64, 25, 12, 22, 11] 
  
#traversing through array elements
for i in range(len(A)): 
      
    #find minimum element in rest of unsorted array 
    min = i 
    for j in range(i+1, len(A)): 
        if A[min] > A[j]: 
            min = j 
              
    #swap min element with 1st element        
    A[i], A[min] = A[min], A[i] 
  
print ("Sorted array") 
for i in range(len(A)): 
    print("%d" %A[i])
