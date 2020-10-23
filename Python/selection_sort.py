
A = [64, 25, 12, 22, 11] 
  
#traversing through array elements
for i in range(len(A)): 
      
    #find minimum element in rest of unsorted array 
    mini = i 
    for j in range(i+1, len(A)): 
        if A[mini] > A[j]: 
            mini = j 
              
    #swap min element with 1st element        
    A[i], A[mini] = A[mini], A[i] 
  
print ("Sorted array") 
for i in range(len(A)): 
    print("%d" %A[i])
