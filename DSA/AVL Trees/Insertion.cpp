//Insertion in AVL Tree
//AVL trees are balanced Binary Search Trees.
//Wee have a new Term call balanced factor
//balanced factor = height of left subtree - height of right subtree
//If balanced factor ranges in  {-1, 0, 1} for each node, then the tree is balanced
//Otherwise it's imbalanced.

//AVL Trees use LL-Rotation, RR-Rotation, LR-Roation, and RR-Rotation to generate a balanced Tree while inserting
//each node after checking for it's balancing factor and identifying the imbalanced nodes.
//In order to save time, we take an extra variable height for each node containing the height of the node or
//maximum levels beneath it.

#include <iostream>
#define endl "\n"
using namespace std;

struct Node{
    Node *lchild;
    int data;
    int height;
    Node *rchild;
}*root = NULL;

//Finding the Height of the Node
int NodeHeight(Node *p){
    int h1, h2;
    h1 = p&&p->lchild?p->lchild->height:0;
    h2 = p&&p->rchild?p->rchild->height:0;
    
    return h1>h2?h1+1:h2+1;
}

//Finding the Balanced Factor
int BalanceFactor(Node *p){
    int lh, rh;
    lh = p&&p->lchild?p->lchild->height:0;
    rh = p&&p->rchild?p->rchild->height:0;
    return lh-rh;
}

//LL Rotation
Node* LLRotation(Node *p){
    Node *pl = p->lchild;
    Node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);

    if(root == p)
        root = pl;
    return pl;
}

//LRRotation
Node* LRRotation(Node *p){
    Node *pl = p->lchild;
    Node* plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);
    p->height = NodeHeight(p);
    if(root == p)
        root = plr;
    return plr;
}

//RR Rotation
Node* RRRotation(Node *p){
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
    p->rchild = prl;
    pr->lchild = p;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    if(root == p)
        root = pr;
    return pr;
}

//RL Rotation
Node* RLRotation(Node *p){
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);
    if(root == p)
        root = prl;
    return prl;
}

//Inserting into AVL Tree
Node* RInsert(Node *p, int key){
    if(p == NULL){
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        p->height = 1;
    }
    
    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);
    p->height = NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 &&BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if(BalanceFactor(p)== -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}

//Dummy Making it easier
Node* RInsert(int key){
    return RInsert(root, key);
}

int main()
{
    int a[] = {10, 20, 30, 25, 28, 27, 5};
    int n = sizeof(a)/sizeof(a[0]);
    root = RInsert(10);
    for(int i=1; i < n; i++)
        root = RInsert(a[i]);

    return 0;
}