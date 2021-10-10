#include <bits/stdc++.h>
#include<set>

using namespace std;

class node {
	public:
	int data;
	node *left, *right;
}*root;

node* GetNode(int d) {
	node *nn=new(node);
	nn->left = NULL;
	nn->right = NULL;
	nn->data = d;
	return nn;
}

void InOrder(node *root) {
	if(root == NULL)
	return ;
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

void StoreData(node *root,set<int> &s){ //&s reference of original set
	if(root == NULL)
	return ;
	StoreData(root->left,s);
	s.insert(root->data);
	StoreData(root->right,s);
}

void ConvertToBST(node *root, auto &it) {
	if(root == NULL)
	return ;
	ConvertToBST(root->left, it);
	root->data = *it;
	it++;
	ConvertToBST(root->right, it);
}

int main()
{
	root = GetNode(8);
	root->left = GetNode(3);
	root->right = GetNode(5);
	root->left->left = GetNode(10);
	root->left->right = GetNode(2);
	root->right->left = GetNode(4);
	root->right->right = GetNode(6);
	InOrder(root);
	
	set<int> s;
	StoreData(root,s);
	auto it = s.begin();
	ConvertToBST(root,it);
	InOrder(root);
}
