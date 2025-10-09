#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node {
   int data;
   struct node *leftChild;
   struct node *rightChild;
};
struct node *root = NULL;
void insert(int data){
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;
   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;
      while(1) {
         parent = current;

         //go to left of the tree
         if(data < parent->data) {
            current = current->leftChild;

            //insert to the left
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }//go to right of the tree
         else {
            current = current->rightChild;

            //insert to the right
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }
   }
}
void inorder_traversal(struct node* root){
   if(root != NULL) {
      inorder_traversal(root->leftChild);
      printf("%d ",root->data);
      inorder_traversal(root->rightChild);
   }
}
int main(){
   int i,n;
   vector<int> vec;
   cout<<"Enter the no of nodes:";
   cin>>n;
   cout<<"Enter elements in a tree";
   for(i = 0; i < n; i++){
       int x;
       cin>>x;
       vec.push_back(x);
   }
   for(int i=0 ;i<vec.size();i++){
        insert(vec[i]);
   }
   printf("\nInorder traversal: ");
   inorder_traversal(root);
   return 0;
}