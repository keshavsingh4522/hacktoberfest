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

int no_nodes(node*root)
{
	if(root==NULL)
		return 0;
	return (no_nodes(root->left)+no_nodes(root->right)+1);
}

int sum_nodes(node*root)
{
	if(root==NULL)
		return 0;
	return (sum_nodes(root->left)+sum_nodes(root->right)+1);
}

int diameter(node*root)
{
	if(root==NULL)
		return 0;

	int h1=height(root->left);
	int h2=height(root->right);
	int case1=h1+h2;
	int case2=diameter(root->left);
	int case3=diameter(root->right);

	return max(case1,max(case2,case3));
}

node* array_tree(int *arr,int start,int end)
{
	int mid=(start+end)/2;
	if(start>end)
		return NULL;

	//making mid element of an array as a root
	node* root=new node(arr[mid]);
	root->left=array_tree(arr,start,mid-1);
	root->right=array_tree(arr,start,mid+1);
	return root;
}

//using preorder and inorder traversal
node* traversaltree(int *pre, int *in,int start,int end)
{
	int i=0,index=-1;
	if(start>end)
		return NULL;
	node*root=new node(pre[i]);

	for(int j=start;j<end;j++)
	{
		if(in[j]==pre[i])
		{
			index=j;
			break;
		}
	}
	i++;
	root->left=traversaltree(pre,in,start,index-1);
	root->right=traversaltree(pre,in,index+1,end);
	return root;
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