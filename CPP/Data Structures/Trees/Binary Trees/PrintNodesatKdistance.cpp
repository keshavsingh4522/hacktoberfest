#include<bits/stdc++.h>
using namespace std;

// tree structure
struct Node{
    // data value to be stored in key variable.
    int key;
    // left and right node pointers
    Node *left,*right;
    // constructor to initialize nodes of tree
    Node(int x){
        key =x;
        left = right = NULL;
    }
};

typedef struct Node* node;

void printKDist(Node* root,int k){
    if(root==NULL) return ;
    if(k==0){cout<<(root->key)<<" ";}
    else{
        printKDist(root->left,k-1);
        printKDist(root->right,k-1);
    }
}



int main(){

    // making tree
    // root node
    int k;
    node root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right = new Node(30);
    root->right->left = new Node(70);
    root->right->right = new Node(80);
    cout<<"Enter the value of k : ";
    cin>>k;
    printKDist(root,k);
   

    return 0;
}

