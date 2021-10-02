/*
Sum of Leaf Nodes 

Easy Accuracy: 54.3% Submissions: 27278 Points: 2
Given a Binary Tree of size N. The task is to complete the function sumLeaf(), that should return the sum of all the leaf nodes of the given binary 
tree.

Input:
First line of input contains number of testcases T. For each testcase, there will be two lines, first of which containing the number of edges 
(between two nodes) in the tree. Next line contains N pairs (considering a and b) with a 'L' (means node b on left of a) or 'R' (means node b on 
right of a) after a and b.

Output:
For each testcase, there will be a single line containing the sum of all leaf nodes in the tree.

User Task:
The task is to complete the function sumLeaf() which takes root reference as argument and returns the sum of all leaf nodes.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L

Output:
5
190

Explanation:
Testcase 1: Leaf nodes in the tree are 2 and 3, and their sum is 5.
 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

int sumLeaf(Node* root);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<sumLeaf(root)<<endl;
  }
  return 0;
}
// } Driver Code Ends


/*Structure of the node of the binary tree is as
struct Node
{
	int data;
	Node *left, *right;
};*/
// function should return the sum of all the 
// leaf nodes of the binary tree 
int sumLeaf(Node* root)
{
if(root==NULL)
return 0;
if(root->left==NULL && root->right==NULL)
return root->data;
return sumLeaf(root->left)+sumLeaf(root->right);
}
