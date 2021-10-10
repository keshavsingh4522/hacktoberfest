#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node*left;
	node*right;
	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
	
};

node* insert(node*root,int data)
{
	if(root==NULL){
		return root=new node(data);}
	if(data<root->data)
	{
		root->left=insert(root->left,data);
	}
	else
		root->right=insert(root->right,data);
	return root;
}

bool search(node*root,int data)
{
	if(root==NULL)
		return false;
	else if(data<root->data)
		return search(root->left,data);
	else
		return search(root->right,data);
	return true;
}

node* delete_node(node*root,int data)
{
	if(root==NULL)
		return NULL;
	else if(data<root->data)
		return delete_node(root->left,data);

	//3 cases
	else if(data==root->data)
	{
		//for leaf node
		if(root->left==NULL and root->right==NULL)
		{
			delete root;
			return NULL;
		}

		//for node having 1 child
		if(root->left!=NULL and root->right==NULL)
		{

			//store root's left child in a temporary node
			node*temp=root->left;
			delete root;
			return temp;
		}
		if(root->left==NULL and root->right!=NULL)
		{
			node*temp=root->right;
			delete root;
			return temp;
		}

		//for 2 child node
		node* replace=root->right;
		while(root->left!=NULL)
			replace=replace->left;
		replace->data=root->data;
		root->right=delete_node(root->right,replace->data);
		return root;
	}

	else
		return delete_node(root->right,data);
}

bool is_BST(node*root,int min=INT_MIN,int max=INT_MAX)
{
	if(root==NULL)
		return false;
	if(root->data<min and root->data>max and is_BST(root->left,min,root->data) and is_BST(root->right,root->data,max))
	{
		return true;
	}
	return false;
}

node* build()
{
	int d;
	cin>>d;
	node*root=NULL;

	while(d!=-1)
	{
		root=insert(root,d);
        cin>>d;
	}
	return root;
}

void print(node*root)
{
	if(root==NULL)
		return;

	cout<<root->data<<" ->";
	print(root->left);
	print(root->right);
}

int main()
{
    node *root=build();
	// build();
	print(root);

	return 0;
}