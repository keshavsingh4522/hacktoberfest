typedef struct  
{ 
    int *heap;    // Min-heap to store k largest elements 
    int size;     // Current number of elements in heap 
    int capacity; // Maximum size (k) 
} KthLargest; 
int kthLargestAdd(KthLargest* kth, int val); 
KthLargest* kthLargestCreate(int k, int* nums, int numsSize)  
{ 
    KthLargest *kth = (KthLargest*)malloc(sizeof(KthLargest)); 
    kth->heap = (int*)malloc(sizeof(int) * k); 
    kth->size = 0; 
    kth->capacity = k; 
    for (int i = 0; i < numsSize; i++)  
    { 
        kthLargestAdd(kth, nums[i]); 
    } 
    return kth; 
} 
int kthLargestAdd(KthLargest* kth, int val)  
{ 
    if (kth->size < kth->capacity)  
    { 
        int i = kth->size; 
        kth->heap[kth->size++] = val; 
        while (i > 0)  
        { 
            int parent = (i - 1) / 2; 
            if (kth->heap[i] < kth->heap[parent])  
            { 
                int temp = kth->heap[i]; 
                kth->heap[i] = kth->heap[parent]; 
                kth->heap[parent] = temp; 
                i = parent; 
            }  
            else { 
                break; 
            } 
        } 
    }  
    else if (val > kth->heap[0])  
    { 
        kth->heap[0] = val; 
        int i = 0; 
        while (1)  
        { 
            int left = 2 * i + 1; 
            int right = 2 * i + 2; 
            int smallest = i; 
 
            if (left < kth->size && kth->heap[left] < kth->heap[smallest])  
            { 
                smallest = left; 
            } 
            if (right < kth->size && kth->heap[right] < kth->heap[smallest])  
            { 
                smallest = right; 
            } 
            if (smallest != i)  
            { 
                int temp = kth->heap[i]; 
                kth->heap[i] = kth->heap[smallest]; 
                kth->heap[smallest] = temp; 
                i = smallest; 
            }  
            else { 
                break; 
            } 
        } 
    } 
    return kth->heap[0]; 
} 
void kthLargestFree(KthLargest* kth)  
{ 
    free(kth->heap); 
    free(kth); 
} 
