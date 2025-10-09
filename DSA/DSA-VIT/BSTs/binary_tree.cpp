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

int main()
{
	node*root=build_tree();
	print(root);

	return 0;
}