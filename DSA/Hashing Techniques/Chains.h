#ifndef Chains_h
#define Chains_h

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
    LinkedList(){first = last = nullptr;}
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
    first = last = nullptr;
}

void LinkedList :: Insert_sorted(int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;
    if(first == nullptr)
        first = last = t;
    else{
        Node *p = first, *q = nullptr;
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
    Node *p = first, *q = nullptr;
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
    return first == nullptr;
}

Node* LinkedList :: Search(int key){
    Node *p = first;
    while(p && p->data != key)
        p = p->next;
    if(p == nullptr) return nullptr;
    return p;
}
//LL Complete


#endif