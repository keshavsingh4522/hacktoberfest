/*Merge Two Balanced Binary Search Trees
You are given two balanced binary search trees e.g., AVL or Red-Black Tree. 
Write a function that merges the two given balanced BSTs into a balanced binary search tree.
 Let there be m elements in the first tree and n elements in the other tree. Your merge function should take O(m+n) time.
In the following solutions, it is assumed that the sizes of trees are also given as input. 
If the size is not given, then we can get the size by traversing the tree */
// C++ program to Merge Two Balanced Binary Search Trees
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
	public:
	int data;
	node* left;
	node* right;
};

// A utility unction to merge two sorted arrays into one
int *merge(int arr1[], int arr2[], int m, int n);

// A helper function that stores inorder
// traversal of a tree in inorder array
void storeInorder(node* node, int inorder[],
							int *index_ptr);

/* A function that constructs Balanced
Binary Search Tree from a sorted array
See https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/ */
node* sortedArrayToBST(int arr[], int start, int end);

/* This function merges two balanced
BSTs with roots as root1 and root2.
m and n are the sizes of the trees respectively */
node* mergeTrees(node *root1, node *root2, int m, int n)
{
	int *arr1 = new int[m];
	int i = 0;
	storeInorder(root1, arr1, &i);

	int *arr2 = new int[n];
	int j = 0;
	storeInorder(root2, arr2, &j);

	int *mergedArr = merge(arr1, arr2, m, n);

	return sortedArrayToBST (mergedArr, 0, m + n - 1);
}


node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return(Node);
}

void printInorder(node* node)
{
	if (node == NULL)
		return;

	printInorder(node->left);

	cout << node->data << " ";

	
	printInorder(node->right);
}

int *merge(int arr1[], int arr2[], int m, int n)
{

	int *mergedArr = new int[m + n];
	int i = 0, j = 0, k = 0;

	while (i < m && j < n)
	{
		
		if (arr1[i] < arr2[j])
		{
			mergedArr[k] = arr1[i];
			i++;
		}
		else
		{
			mergedArr[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i < m)
	{
		mergedArr[k] = arr1[i];
		i++; k++;
	}

	while (j < n)
	{
		mergedArr[k] = arr2[j];
		j++; k++;
	}

	return mergedArr;
}

void storeInorder(node* node, int inorder[], int *index_ptr)
{
	if (node == NULL)
		return;

	storeInorder(node->left, inorder, index_ptr);

	inorder[*index_ptr] = node->data;
	(*index_ptr)++; 

	storeInorder(node->right, inorder, index_ptr);
}

node* sortedArrayToBST(int arr[], int start, int end)
{
	
	if (start > end)
	return NULL;

	int mid = (start + end)/2;
	node *root = newNode(arr[mid]);

	
	root->left = sortedArrayToBST(arr, start, mid-1);

	
	root->right = sortedArrayToBST(arr, mid+1, end);

	return root;
}


int main()
{
	node *root1 = newNode(100);
	root1->left	 = newNode(50);
	root1->right = newNode(300);
	root1->left->left = newNode(20);
	root1->left->right = newNode(70);

	
	node *root2 = newNode(80);
	root2->left	 = newNode(40);
	root2->right = newNode(120);

	node *mergedTree = mergeTrees(root1, root2, 5, 3);

	cout << "Following is Inorder traversal of the merged tree \n";
	printInorder(mergedTree);

	return 0;
}

