// Bucket Sort
// Bucket sort is a comparison sort algorithm that operates on elements by dividing them into different buckets
// and then sorting these buckets individually. Each bucket is sorted using a separate sorting algorithm or by
// recursively applying the bucket sort algorithm.
// It is a distribution sort.

//Time Complexity = O(n+k) where k = no. of buckets and n = no. of elements; O(n^2) in worst case
//Space complexity = O(n+k)
#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class LinkedList{
    private:
    Node *first, *last;

    public:
    LinkedList(){first = last = NULL;}
    ~LinkedList();
    void Insert(int x);
    int Delete();
    bool isEmpty();
    void Sort();
};

LinkedList :: ~LinkedList()
{
    Node *p;
    while(first){
        first = first->next;
        delete p;
    }
    first = last = NULL;
}

void LinkedList :: Insert(int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if(first == NULL)
        first = last = t;
    else{
        last->next = t;
        last = last->next;
    }
}

int LinkedList :: Delete()
{
    if(first == NULL)  return -1;
    Node * tr = first;
    first = first->next;
    int x = tr->data;
    delete tr;
    return x;
}

bool LinkedList :: isEmpty()
{
    return first == NULL;
}

void LinkedList :: Sort() 
{
    if(!first || !first->next) return; // Array is empty or has one element
    Node* sorted = nullptr;
    Node* current = first;
    while (current != nullptr) {
        Node* next = current->next;
        if(sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while(temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    first = sorted;

    // reupdate last pointer after sorting
    last = first;
    while(last && last->next) {
        last = last->next;
    }
}

int Max(int A[], int n)
{   
    int mx = INT32_MIN;
    for(int i=0; i < n; i++)
        if(mx < A[i]) mx = A[i];
    return mx;
}

void BucketSort(int A[], int n)
{
    int max = Max(A, n);
    // Create n buckets (linked lists)
    LinkedList *bin = new LinkedList[n];

    // Put array elements in different buckets
    for(int i=0; i < n; i++)
    {
        int bin_idx = (long long)n * A[i] / (max + 1);
        bin[bin_idx].Insert(A[i]);
    }
    
    // Sort individual buckets and concatenate
    int i=0;
    for(int j=0; j < n; j++)
    {
        bin[j].Sort(); // Sort each bucket
        while(!bin[j].isEmpty())
            A[i++] = bin[j].Delete();
    }
    delete []bin;
}

int main()
{
    int A[] = {237, 140, 259, 348, 152, 163, 1244, 48, 36, 62};
    int n = sizeof(A)/sizeof(A[0]);

    BucketSort(A, n);
    //Display
    cout << "Sorted List : ";
    for(int i=0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}