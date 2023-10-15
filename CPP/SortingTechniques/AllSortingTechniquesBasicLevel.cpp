//This is a culmination of all Sorting Techniques we have learned so far.
//I will try to create template for each here, so it can be used later for multiple datatypes.

#include <iostream>
#define endl "\n"
using namespace std;
#include <time.h>

template <class T>
class Sorting{
    private:
    T *A;
    int n;

    private:
    int Randomized_Partition(int l, int h);
    void Merge(int l, int mid, int h);

    public:
    Sorting(T arr[], int n);
    ~Sorting();
    //Comparison based sorting trechniques
    void BubbleSort(); //O(n^2) - max || O(n) - min
    void InsertionSort(); //O(n^2) - max || O(n) - min
    void SelectionSort();//O(n^2)
    void QuickSort(int l, int h);//O(nlogn) - Best Case || O(n^2) - Worst Case
    void QuickSort(){QuickSort(0, n);}//Dummy for QuickSort
    void IMergeSort();//Iterative version of Merge Sort
    void RMergeSort(int l, int h);//Average Case time - O(nlogn) - same for all cases(Recursive)
    void RMergeSort(){RMergeSort(0, n-1);}
    void ShellSort();//O(nlogn) for gap = n/2, may also vary O(n^3/2) and O(n^5/3) for varying gap, say prime number
    
    //Except MergeSort all of the above follow inplace sorting.
    //Only Bubble Sort(modified adoptive), Insertion Sort(adoptive by nature), Shell Sort(derived from Insertion Sort) are adoptive.
    //Bubble Sort, Insertion Sort, Merge Sort, Shell Sort are stable.

    //Index based Sorting Techniques
    //Time Complexity - O(n)
    //Space Complexity - O(n)
    void CountSort(); 
    void BucketSort();
    void RadixSort(); //O(dn) where d = no of digits of max element, n = no of elements

    void Display();
};

template <class T>
Sorting<T> :: Sorting(T arr[], int n)
{
    A = new T[n+1];
    A[n] = INT32_MAX;
    for(int i=0; i < n; i++) A[i] = arr[i];
    this->n = n;
}

template <class T>
Sorting<T> :: ~Sorting(){
    delete [] A;
    this->n = 0;
}

template <class T>
void Sorting<T> :: BubbleSort(){
    int flag = 0;
    for(int i=0; i < n-1; i++){
        for(int j=0; j < n-i-1; j++){
            if(A[j] > A[j+1])
                swap(A[j], A[j+1]);
            flag = 1;
        }
        if(flag == 0) break;   
    }
}

template <class T>
void Sorting<T> :: InsertionSort()
{
    for(int i=1; i < n; i++)
    {
        T temp = A[i];
        int j = i-1;
        while(j > -1 && A[j] > temp)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}

template <class T>
void Sorting<T> :: SelectionSort()
{
    for(int i=0; i<n; i++)
    {
        int j, k;
        for(j=k=i; j < n; j++){
            if(A[j] < A[k]) k = j;
        }
        swap(A[i], A[k]);
    }
}

template <class T>
int Sorting<T> :: Randomized_Partition(int l, int h)
{
    srand(time(0));
    //Randomize
    int pivot_index = l + rand()%(h-l);
    swap(A[l], A[pivot_index]);

    T pivot = A[l];
    int i=l, j=h;
    while(i < j)
    {
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        if(i < j)
            swap(A[i], A[j]);
    }
    swap(A[l], A[j]);
    return j;
}

template <class T>
void Sorting<T> :: QuickSort(int l, int h)
{
    if(l < h)
    {
        int split = Randomized_Partition(l, h);
        QuickSort(l, split);
        QuickSort(split+1, n);
    }
}

template <class T>
void Sorting<T> :: Merge(int l, int mid, int h)
{
    int i = l, j = mid+1, k=0;
    int B[h-l+1]; //Auxiliary Array used for merging
    while(i <= mid && j <= h)
    {
        if(A[i] <= A[j]) //= for stability
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while(i <= mid) B[k++] = A[i++];
    while(j <= h) B[k++] = A[j++];

    for(int i=l; i <= h; i++) A[i] = B[i-l];
}

template <class T>
void Sorting<T> :: IMergeSort()
{
    int p, i, j, l, h, mid;
    for(p=2; p <=n; p = p*2){
        for(i = 0; i+p-1 < n; i+=p){
            l = i;
            h = l+p-1;
            mid = (l+h)/2;
            Merge(l, mid, h);
        }
        if(i < n)
            Merge(i,(i+n-1)/2,n-1);
    }
    if(p/2 < n)
        Merge(0, p/2-1, n-1);
}

template <class T>
void Sorting<T> :: RMergeSort(int l, int h)
{
    if(l < h)
    {
        int mid = (l+h)/2;
        RMergeSort(l, mid);
        RMergeSort(mid+1, h);
        Merge(l, mid, h);
    }
}

template <class T>
void Sorting<T> :: ShellSort()
{
    int gap = n/2;
    for(; gap > 0; gap/=2)
    {
        for(int i=gap; i < n+1; i++){
            int j = i-gap;
            T temp = A[i];
            while(j > -1 && A[j] > temp){
                A[j+gap] = A[j];
                j = j-gap;
            }
            A[j+gap] = temp;
        }
    }
}

template <class T>
void Sorting<T> :: CountSort()
{
    T m = A[0];
    int i, j;
    for(i=1; i < n; i++) m = max(m, A[i]);

    int *Count = new int[m+1];
    for(i=0; i < m+1; i++) Count[i] = 0; //Initialization
    for(i=0; i < n; i++) Count[A[i]]++; //Storing the occurrences of elements

    i = 0;
    for(j=0; j < m+1; j++)
    {
        if(Count[j] > 0){
            A[i++] = j;
            Count[j]--;
        }
    }        
};

//For both bucket/bn sort and radix sort we need a Linked List
//Linked List start
template <class T>
class Node{
    public:
    T data;
    Node *next;
};

template <class T>
class LinkedList{
    private:
    Node<T> *first, *last;

    public:
    LinkedList(){first = last = NULL;}
    ~LinkedList();
    void Insert(T x);
    T Delete();
    bool isEmpty();
};


template <class T>
LinkedList<T> :: ~LinkedList(){
    Node<T> *p;
    while(first){
        p = first;
        first = first->next;
        delete p;
    }
    first = last = NULL;
}

template <class T>
void LinkedList<T> :: Insert(T x){
    Node<T> *t = new Node<T>;
    t->data = x;
    t->next = NULL;
    if(first == NULL)
        first = last = t;
    else{
        last->next = t;
        last = last->next;
    }
}

template <class T>
T LinkedList<T> :: Delete()
{
    T x = -1;
    if(first == NULL)
        cout << "Linked List is Empty\n";
    else{
        Node<T> *tr = first;
        first = first->next;
        x = tr->data;
        delete tr;
    }
    return x;
}

template <class T>
bool LinkedList<T> :: isEmpty()
{
    return first == NULL;
}
//Linked List end

template <class T>
void Sorting<T> :: BucketSort()
{
    T m = A[0];
    int i,j;
    for(i=1; i < n; i++) m = max(m, A[i]);

    LinkedList<T> *Bin = new LinkedList<T>[m+1];
    //No need to intialize, already initialized to null...

    for(i=0; i < n; i++) Bin[A[i]].Insert(A[i]); //Inserting the Nodes
    
    i=0;
    for(j = 0; j < m+1; j++){
        while(!Bin[j].isEmpty()){
            A[i++]= Bin[j].Delete();
        }
    }
};

template <class T>
void Sorting<T> :: RadixSort()
{
    int m, d=1;
    for(int i=1; i < n; i++) m = max(m, A[i]);
    while(d < m)
    {
        int i, j;
        LinkedList<T> *Bin = new LinkedList<T>[n];
        for(i=0; i <n; i++) Bin[(A[i]/d)%10].Insert(A[i]);

        i=0;
        for(j=0; j < n; j++){
            while(!Bin[j].isEmpty())
                A[i++] = Bin[j].Delete();
        }
        d = d*10;
    }
};

template <class T>
void Sorting<T> :: Display()
{
    for(int i=0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{
    int A[] = {81, 12, 67, 258, 49, 34, 23, 110, 30, 73, 289, 6};
    int n = sizeof(A)/sizeof(A[0]);

    Sorting<int> srt(A, n);
    srt.RadixSort();
    cout << "Sorting : ";
    srt.Display();
    return 0;
}
