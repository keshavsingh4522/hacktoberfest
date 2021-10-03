
# KMP algorithm for pattern matching

def pattern_array(pattern):
    arr=[0]

    for i in range(1,len(pattern)):
        #print(pattern[i]+"   "+pattern[:i])
        if pattern[i] in pattern[:i+1]:
            arr.append(pattern[:i].find(pattern[i])+1)
        else:
            arr.append(0)
    return(arr)


def kmp(text,pattern,arr):
    m=len(pattern)
    n=len(text)
    if m==0:
        return 'Pattern found at index 0'
    
    if n<m:
        return 'No Pattern Found'
    
    i=0
    j=-1
    while i<n:
        while i<n and j<m-1 and text[i]==pattern[j+1]:
            #print("First While:- "+str(i))
            i+=1
            j+=1

        if j==m-1:
            return 'Pattern found at index '+str(i-m+1)

        if text[i]!=pattern[j+1]:
            while j>=0:
                if pattern[j+1]!=text[i]:
                    j=arr[j]-1
                else:
                    break
            if j!=-1:
                j+=1
            i+=1
        

    return 'No Pattern Found'


text='ABABCABCABABABD'
pattern='ABABD'
arr=pattern_array(pattern)
print(arr)
print(kmp(text,pattern,arr))
