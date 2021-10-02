//Linear Probing
//It is one of the collision resolution technique under Closed Hashing.
//It uses modified hash function h'(key) = (h(key) + f(i)) where f(i) = i for i=0,1,2,..
//We contiuously increment the value of i till we get encounter a blank space for inserting element.

//As the technique uses modulo a 2nd time, we get a circular hash table.
//Seach for key present in hash table will continue and we will increment and compare till we find the key.
//Search for unsuccessful key stops at a blank space.
//Deletion in Linear probing is complicated and generates too many situations and questions.
//Just deleting an element in linear probing will complicate matter.
//We will also have to shift the subsequent keys for non-matching indices till we get a matching index for a particular element.
//Alternatively, we can rehash the entirety table or also take an alternate flag which marks the deletion instead of actual deletion.

//But, a lot of extra effort is required and hence deletion is not suggested/recommended for Linear Probing.

//*** Anothe very important thing about Linear probing is that we take the size of hash table atleast double the size 
//of max elements to be inserted.
//this is done to increase efficiency of search as well as solve looping problem in case the whole table is filled.
//So we have ************** lambda <= 0.5 *******************

//Analysis
//For successful search t = (1/lambda)*ln(1/(1-lambda))
//For unsuccessful search t = 1/(1-lambda)

//Drawback
//1. Space is wasted since only half of the space is used for inserting
//2. Lots of keys mamy accumulate causing Primary clustring of keys problem.
//3. Deletion is not suitable for Linear Probing.

#include <iostream>
#define endl "\n"

using namespace std;

#define SIZE 10
#define hash(x) x%SIZE
#define f(i) i

int Modified_hash(int key, int i){
    return (hash(key)+f(i))%SIZE;
}

void Insert(int hash[], int key){
    int index = Modified_hash(key, 0);
    int i=1;
    while(hash[index] != -1)
        index = Modified_hash(key, i++);
    hash[index] = key;
}

int Search(int hash[], int key){
    int index = hash(key);
    while(hash[index%SIZE] != -1 && hash[index%SIZE]!=key)
        index++;
    if(hash[index % SIZE] == -1)
        return -1;
    return index%SIZE;
}

int main()
{
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A)/sizeof(A[0]);

    int hash[10];
    for(int i=0; i < 10; i++) hash[i] = -1;

    //Insert
    for(int i=0; i <n; i++) Insert(hash, A[i]);

    cout << "Key 45 is at index " << Search(hash, 45) << endl;

    return 0;
}

//Challenge : Try to make a class showing the workings of linear probing and other probing methods



