#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};
node* newnode(int x)
{
	node* temp=new node;
	temp->data=x;
	temp->left=temp->right=0;
	return temp;
}

bool isomorphic(node* root,node* root1)
{
if(root==NULL && root1==NULL)
return true;
if((root==NULL && root1!=NULL) || (root!=NULL && root1==NULL))
return false;
if(root->data!=root1->data)
return false;
return (isomorphic(root->left,root1->left) &&isomorphic(root->right,root1->right));
}

int main()
{
	node* root=NULL;
	root =  newnode(4);  
    root->left = newnode(2);  
    root->right = newnode(5);  
    root->left->left = newnode(1);  
    root->left->right = newnode(3);  
	node* root1=NULL;
	root1 =  newnode(4);  
    root1->left = newnode(2);  
    root1->right = newnode(5);  
    root1->left->left = newnode(1);  
    root1->left->right = newnode(3);  
	
	cout<< isomorphic(root,root1);
	//    cout<<lca(root,2,9)->data;
	return 0;
}



