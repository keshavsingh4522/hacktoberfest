                                    //Quadratic Probing
//Quadratic Probing is similar to Linear Probing except that it uses f(i) = i^2 instead of i.
//It has the same drawbacks as linear probing and thus deleting is not convenient here as well.
//Quadratic probing is better then linear probing because it overcomes the problem of
//Primary cllustering of elements
//Since now elements are stored with some gap.

//Analysis
// time is same as Linear Probing
//Avg. Successful Search - t = (1/lambda)*ln(1/(1-lambda))
//Avg unsuccessful search - t = 1/(1-lambda)

#include <iostream>
using namespace std;
#define endl "\n"
#define SIZE 10

int Hash(int key){return key%SIZE;}

int QuadraticProbe(int H[], int index){
    int i=1;
    while(H[index] != 0)
    {
        index = (index+i*i)%SIZE;
        i++;
    }
    return index;
}

void Insert(int H[], int key)
{
    int index = Hash(key);
    if(H[index] != 0)
        index = QuadraticProbe(H, index);

    H[index] = key;
}

int Search(int H[], int key)
{
    int index = Hash(key);
    int i=1;
    while(H[index] != 0 && H[index] != key)
    {
        index = (index+i*i)%SIZE;
        i++;
    }
    if(H[index] == 0) return -1;
    return index;
}

int main()
{
    int A[] = {22, 32, 42, 57, 67, 17};
    int n = sizeof(A)/sizeof(A[0]);

    int H[10] = {0};
    for(int i=0; i <n; i++)
        Insert(H, A[i]);

    printf("\n%d is at index %d\n", 57, Search(H, 57));
    printf("\n%d is at index %d\n", 17, Search(H, 17));
    printf("\n%d is at index %d\n", 25, Search(H, 25));
    return 0;
}