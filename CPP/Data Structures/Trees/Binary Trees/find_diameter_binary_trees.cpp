// C++ program to find the diameter of a Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left, *right;
};

struct node* newNode(int data);

int diameterOpt(struct node* root, int* height)
{
	int lh = 0, rh = 0;

	int ldiameter = 0, rdiameter = 0;

	if (root == NULL) {
		*height = 0;
		return 0; 
	}

	ldiameter = diameterOpt(root->left, &lh);
	rdiameter = diameterOpt(root->right, &rh);

	*height = max(lh, rh) + 1;

	return max(lh + rh + 1, max(ldiameter, rdiameter));
}

struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

// Driver Code
int main()
{

	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	int height = 0;
	cout << "Diameter of the given binary tree is " << diameterOpt(root, &height);

	return 0;
}


