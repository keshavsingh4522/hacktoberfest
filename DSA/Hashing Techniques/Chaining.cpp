//Chaining
//Chaining is a technique under Open hasing as a Solution to collision problem in Modulus hashing.
//In chaing we take an array of addresses as hash table and store the keys in each node as per the index from hash function
//h(x) = x%SIZE or any other convenient as per the programmer
//The size of the table is expandable to infinity and there is not limit to number of elements stored.
//This is because we are using array of Linked List.

//In case of collision, it is better to store the colliding keys in sorted order for better efficiency in searching.
//Analysis :
//Analysis in collision is based on Loading Factor(lambda) in contrary to other data strcuture, where we take no of elements
//Laoding factor is the max number of elements that can be loaded at a praticular index.
//or better to say max no of elements we are expecting at any index.
//Loading factor(lambda) = No of Elements(n)/size of Hash table

//Insetion takes O(lambda) time same as Insert_sorted in LL
//Delettion also takes O(lambda) time
//Searching takes O(lambda) or better to say for:
//1. Successful Search - avg case - 1 + lambda/2
//2. Unsuccessful Search - 1 + lambda

//Drawback - if not a proper hashing function is used, all the elements may end up at the same index.

#include <iostream>

using namespace std;

//implemetation of LL
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
    void Insert_sorted(int x);
    int Delete(int key);
    bool isEmpty();
    Node* Search(int key);
};

LinkedList :: ~LinkedList()
{
    Node *p;
    while(first)
    {
        p = first;
        first = first->next;
        delete p;
    }
    first = last = NULL;
}

void LinkedList :: Insert_sorted(int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if(first == NULL)
        first = last = t;
    else{
        Node *p = first, *q = NULL;
        while(p && x > p->data){
            q = p;
            p = p->next;
        }

        if(p == first){
            t->next = first;
            first = t;
        }else{
            t->next = p;
            q->next = t;
        }
    }
}

int LinkedList :: Delete(int key){
    int x = -1;
    Node *p = first, *q = NULL;
    while(p && p->data != key)
    {
        q = p;
        p = p->next;
    }
    if(p == first){
        x = first->data;
        first = first->next;
        delete p;
    }else{
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

bool LinkedList :: isEmpty()
{
    return first == NULL;
}

Node* LinkedList :: Search(int key){
    Node *p = first;
    while(p && p->data != key)
        p = p->next;
    if(p == NULL) return NULL;
    return p;
}
//LL Complete

//Chaining
int Hash(int key)
{
    return key%10;
}

//Insert in Hash table
void hInsert(LinkedList htb[], int key)
{
    int index = Hash(key);
    htb[index].Insert_sorted(key);
}

Node* hSearch(LinkedList htb[], int key)
{
    Node *t = NULL;
    int index = Hash(key);
    t = htb[index].Search(key);
    return t;
}

int hDelete(LinkedList htb[], int key)
{
    int x = -1;
    int index = Hash(key);
    x = htb[index].Delete(key);
    return x;
}

int main()
{
    LinkedList htb[10];
    hInsert(htb, 16);
    hInsert(htb, 12);
    hInsert(htb, 25);
    hInsert(htb, 39);
    hInsert(htb, 122);
    hInsert(htb, 5);
    hInsert(htb, 68);
    hInsert(htb, 75);
    hInsert(htb, 6);

    Node *t = hSearch(htb, 5);
    if(t) cout << t->data << " is in Hash Table\n";
    else cout << "Search Unsuccessful\n";

    t = hSearch(htb, 125);
    if(t) cout << t->data << " is in Hash Table\n";
    else cout << "Search Unsuccessful\n";

    cout << hDelete(htb, 5) << " is Deleted\n";
    t = hSearch(htb, 5);
    if(t) cout << t->data << " is in Hash Table\n";
    else cout << "Search Unsuccessful\n";
    return 0;
}