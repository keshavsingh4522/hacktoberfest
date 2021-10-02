//Double Hashing
//Double hashing as the name suggest makes use of two hashing techniques combined to produce and index.
//Double hashing function h'(key) = (h1(key) + h2(key))%SIZE
//where h1(key) = key % SIZE and h2(key) = R - key%R, where R is the first prime number before key on number line.
//Using Double Hashing index allocation becomes mych more easy, and collision becames less frequent.
//This is surely an improvement to linear and quadratic probing.

//All the other rules and drawback apply to Double hashing as well, as situations might still occur though they may not be
//frequent. Deletion is not convenient in Open Addressing techniques however it can be made convenient.

//Implementation
#include <iostream>
using namespace std;
#define endl "\n"

#define SIZE 10

int Hash1(int key)
{
    return key%SIZE;
}

int R = 0;

int lastPrime(int key)
{
    for(int i=key-1; i >= 2; i--)
    {
        int count = 0;
        for(int j = 2; j < i; j++)
        {
            if(i%j == 0){
                count++;
                break;
            }
        }
        if(count == 0)
            return i;
    }
    return -1;
}

int Hash2(int key)
{
    if(R == 0)
        R = lastPrime(SIZE);
    return R - key%R;
}

//Insert using Double Hashing
void Insert(int H[], int key)
{
    int index, h1;
    index = h1 = Hash1(key);
    if(H[index] != 0){
        int i=1;
        int h2 = Hash2(key);
        while(H[index] != 0){
            index = (h1 + i*h2)%SIZE; //Double Hashing
            i++;
        }
    }
    H[index] = key;
}   

int Search(int H[], int key)
{
    int search_index = Hash1(key);
    int h2 = Hash2(key);
    int i = 1;
    while(H[search_index] != 0 && H[search_index] != key){
        search_index = (search_index + i*h2)%SIZE;
        i++;
    }
    if(H[search_index] != key)
        return -1;
    return search_index;
}

int main()
{
    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A)/sizeof(A[0]);

    int H[SIZE] = {0};//Hash Table
    for(int i=0; i <n; i++)
        Insert(H, A[i]);

    for(int i=0; i < n; i++)
        printf("%d is at index %d\n", A[i], Search(H, A[i]));
    printf("%d is at index %d\n", 23, Search(H, 23));

    return 0;
}