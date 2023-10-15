#include <iostream>
#include "treenode.h"
#include <queue>
using namespace std;

treenode<int> * takeInput(){ // level wise input
    int rootData;
    cout << "Enter The Data of the Root Element : ";
    cin >> rootData;
    treenode <int> * root = new treenode <int>(rootData);
    queue <treenode <int>*> q1;
    q1.push(root);
    while(q1.size() != 0){
        treenode<int>* front = q1.front();
        q1.pop();
        int noOfChildren;
        cout << "Enter the no of children of "<< front -> data << " : ";
        cin >> noOfChildren;
        for (int i =0;i<noOfChildren;i++){
            int nodeData;
            cout << "Enter the " << i+1 << " children of " << front ->data << " : ";
            cin >> nodeData;
            treenode <int>* newNode = new treenode<int>(nodeData);
            front -> children.push_back(newNode);
            q1.push(newNode);
        }
    }
    return root;
}

void printTree(treenode <int> * root){ 
    if (root == NULL){
        return; 
    }
    cout << root -> data << " : ";
    for (int i =0;i<root -> children.size();i++){
        cout << root -> children[i]->data << " , "; 
    }
    cout << endl;
    for (int i =0;i<root -> children.size() ; i++){
        printTree(root -> children[i]);
    }
}

int noOFNodes(treenode<int> * root){ 
    int sum = 1; // on account of the root node
    for (int i =0;i<root -> children.size();i++){
       sum += noOFNodes(root -> children[i]);
    }
    return sum;
}

int main(){
    treenode <int> * root = takeInput();
    printTree(root);
    cout << "The no of nodes are : " << noOFNodes(root);
    return 0;
}