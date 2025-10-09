#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*right;
	node*left;

	node(int d)
	{
		data=d;
		node*right=NULL;
		node*left=NULL;
	}
};

node* build_tree()
{
	int d;
	cin>>d;
	if(d==-1)
		return NULL;
	node* root=new node(d);
	root->right=build_tree();
	root->left=build_tree();
	return root;
}

void print(node*root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ->";
	print(root->right);
	print(root->left);
}

void preorder(node*root)
{
	if(root==NULL)
		return;

	//follow root left right
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node*root)
{
	if(root==NULL)
		return;

	//follow left root right
	preorder(root->left);
	cout<<root->data<<" ";
	preorder(root->right);
}

void postorder(node*root)
{
	if(root==NULL)
		return;

	//follow left right root
	preorder(root->left);
	preorder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	node*root=build_tree();
	print(root);
	inorder(root);
	cout<<"\n";
	postorder(root);

	return 0;
}