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

int height(node*root)
{
	if(root==NULL)
		return 0;
	int left_size=height(root->left);
	int right_size=height(root->right);
	return max(left_size,right_size)+1;
}

void levelorder(node*root,int k)
{
	if(root==NULL)
		return;
	if (k==1)
	{
		cout<<root->data<<" ";
		return;
	}
	levelorder(root->left,k-1);
	levelorder(root->right,k-1);
}

void bfs(node*root)
{
	queue<node*>q;
	q.push(root->data);
	while(!q.empty())
	{
		node*f=q.front();
		cout<<f->data<<" ";
		q.pop();

		//last node condition
		if(f->left)
			q.push(f->left);
		if(f->right)
			q.push(f->right);
	}
}

int main()
{
	node*root=build_tree();
	print(root);
	inorder(root);
	cout<<"\n";
	postorder(root);
	cout<<"\n";
	height(root);
	cout<<"\n";
	

	return 0;
}