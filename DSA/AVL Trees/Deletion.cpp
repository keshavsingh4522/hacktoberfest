//Deletion in AVL Trees is same as that of Binary Trees, with the expansion that after
//The element is deleted, then we have to balance the trees as the LL, RR, LR, or RL-rotation
//whichever is apllicable.
//Though we can futher distinguish it into types based on the central node balance factor and whether element
//deleted is from the left or right... These disinctions include
//1. L1 rotation - deletion from right, central node with balance factor 1
//2. L-1 rotation - deletion from right, central node with balance factor -1
//3. L0 rotation - deletion from right, central node with balance factor 0 (Any of L1 or L-1 is applicable)
//4. R1 rotation - deletion from left, central node with balance factor 1
//5. R-1 rotation - deletion from left, central node with balance factor -1
//6. R0 rotation - deletion from left, central node with balance factor 0 (Any of R1 or R-1 is applicable)

#include <iostream>
#define endl "\n"
using namespace std;

struct Node{
    Node *lchild;
    int data;
    Node *rchild;
    int height;
}*root = NULL;

int NodeHeight(Node *p);
int BalanceFactor(Node *p);
Node* LLRotation(Node *p);
Node* LRRotation(Node *p);
Node* RRRotation(Node *p);
Node* RLRotation(Node *p);
int Height(Node *p);

//Main program for Deletion
Node* InPre(Node *p){
    while(p && p->rchild)
        p = p->rchild;
    return p;
}

Node* InSucc(Node *p){
    while(p && p->lchild)
        p = p->lchild;
    return p;
}

Node* Delete(Node *p, int key){
    Node *t;
    if(p == NULL) return NULL;
    if(p->lchild == NULL && p->rchild == NULL){
        if(p == root)
            p = NULL;
        delete p;
        return NULL;
    }

    if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild, key);
    else{
        if(Height(p->lchild) > Height(p->rchild)){
            t = InPre(p->lchild);
            p->data = t->data;
            p->lchild = Delete(p->lchild, t->data);
        }
        else{
            t = InSucc(p->rchild);
            p->data = t->data;
            p->rchild = Delete(p->rchild, t->data);
        }
    }
    p->height = NodeHeight(p);

    //Modification
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) //Type L1
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) //Type L-1
        return LRRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0) //Type L0
        return LLRotation(p); //Alternatively, can also use LRRotation
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) //Type R1
        return RRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) //Type R-1
        return RLRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0) //Type R0
        return RRRotation(p);
    return p;
}

//Insert Start
int NodeHeight(Node *p)
{
    int h1, h2;
    h1 = p&&p->lchild?p->lchild->height:0;
    h2 = p&&p->rchild?p->rchild->height:0;
    return h1>h2?h1+1:h2+1;
}

int BalanceFactor(Node *p){
    int hl, hr;
    hl = p&&p->lchild?p->lchild->height:0;
    hr = p&&p->rchild?p->rchild->height:0;
    return hl-hr;
}

//Rotations
Node* LLRotation(Node *p){
    Node* pl = p->lchild;
    Node* plr = pl->rchild;
    p->lchild = plr;
    pl->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    if(root == p)
        root = pl;
    return pl;
}

Node* LRRotation(Node *p){//Insertion
    Node* pl = p->lchild;
    Node* plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height =  NodeHeight(plr);
    if(root == p)
        root = plr;
    return plr;
}

Node* RRRotation(Node *p)
{
    Node* pr = p->rchild;
    Node* prl = pr->lchild;
    p->rchild = prl;
    pr->lchild = p;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    if(root == p)
        root = pr;
    return pr;
}

Node* RLRotation(Node *p){
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if(root == p) root = prl;
    return prl;
}

Node* RInsert(Node *p, int key){
    if(p == NULL){
        p= new Node;
        p->data = key;
        p->height = 1;
        p->lchild = p->rchild = NULL;
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);
    
    p->height = NodeHeight(p);
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation (p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);
    return p;
}
//Insert Complete

int Height(Node *p){
    if(p)
    {
        int x, y;
        x = Height(p->lchild);
        y = Height(p->rchild);
        return x>y?x+1:y+1;
    }
    return 0;
}

int main()
{
    int a[] = {20, 10, 30, 40};
    int n = sizeof(a)/sizeof(a[0]);
    root = RInsert(root, a[0]);
    for(int i=1; i < n; i++)
        RInsert(root, a[i]);
    
    int key;
    cout << "Enter Value to Delete : ";
    cin >> key;
    root = Delete(root, key);

    return 0;
}