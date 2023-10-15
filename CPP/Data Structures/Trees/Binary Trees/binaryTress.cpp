#include <iostream>
using namespace std;
#include <queue>
#include <cstdlib>
#include "binaryTreeNode.h"

binarynode <int> * takeInput(){ // level wise input
    cout << "Enter the root data : ";
    int rootData;
    cin >> rootData;
    binarynode <int> * root = new binarynode<int>(rootData);
    queue <binarynode<int>*> q1;
    q1.push(root);
    while(q1.size() != 0){
        binarynode <int> * front = q1.front();
        q1.pop();
        cout << "Enter the left child of " << front -> data << " : ";
        cin >> rootData;
        binarynode <int> * leftChild = (rootData != -1) ? new binarynode<int>(rootData) : NULL;
        cout << "Enter the right child of " << front -> data << " : ";
        cin >> rootData;
        binarynode <int> * rightChild = (rootData != -1) ? new binarynode<int>(rootData) : NULL;
        front -> left = leftChild;
        front -> right = rightChild;
        if (leftChild != NULL) q1.push(leftChild);
        if (rightChild !=NULL) q1.push(rightChild);
    }
    return root;
}

void printTree(binarynode <int> * root){
    if (root == NULL) return;
    cout << root -> data << " : ";
    if (root -> left != NULL){
        cout << "L " <<  root -> left -> data << " , ";
    }
    if (root -> right != NULL){
        cout <<  "R " <<root -> right -> data << " ";
    }
    cout << endl;
    printTree(root -> left);
    printTree(root -> right);
}

int height(binarynode <int> * root){ // cn way, better way infact the best way
    if (root == NULL) return 0;
    return 1 + max(height(root -> left), height(root -> right));
}

int countNoOfNodes(binarynode <int> * root){ // well done
    if (root == NULL) return 0;
    int count = 1; // on account of root node
    count += countNoOfNodes(root -> left) + countNoOfNodes(root -> right);
    return count;
}

int main (){
    binarynode <int> * root = takeInput();
    printTree(root);
    cout << "Height of the tree is : " << height(root);
    return 0;
}