#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *CreateTree()
{
    string v;
    cin >> v;
    
    if (v == "n")
    {
        return NULL;
    }
    
    int w=stoi(v);
    node *root = new node(w);
    root->left = CreateTree();
    root->right = CreateTree();
    return root;
}


  
  void display(node *root) {
    if(root==NULL)
    {
      return;
    }

    string str = "";
    str += (root->left) == NULL ? "." : to_string(root->left->data) + "";
    str += " <- " + to_string(root->data) + " -> ";
    str += (root->right) == NULL ? "." : to_string(root->right->data) + "";
    cout<<str<<endl;

    display(root->left);
    display(root->right);
  }
  
   int height(node *root) {
    if(root == NULL){
      return -1;
    }
    
    int lh = height(root->left);
    int rh = height(root->right);
    int th = max(lh, rh) + 1;
    return th;
  }
  
bool isBalanced(node* root, int* height) 
{ 
  
    /* lh --> Height of left subtree  
    rh --> Height of right subtree */
    int lh = 0, rh = 0; 
  
    /* l will be true if left subtree is balanced  
    and r will be true if right subtree is balanced */
    int l = 0, r = 0; 
  
    if (root == NULL) { 
        *height = 0; 
        return 1; 
    } 
  
    /* Get the heights of left and right subtrees in lh and rh  
    And store the returned values in l and r */
    l = isBalanced(root->left, &lh); 
    r = isBalanced(root->right, &rh); 
  
    /* Height of current node is max of heights of left and  
    right subtrees plus 1*/
    *height = (lh > rh ? lh : rh) + 1; 
  
    /* If difference between heights of left and right  
    subtrees is more than 2 then this node is not balanced  
    so return 0 */
    if (abs(lh - rh) >= 2) 
        return 0; 
  
    /* If this node is balanced and left and right subtrees  
    are balanced then return true */
    else
        return l && r; 
} 

int main()
{
    int p;cin>>p;
    node *root = CreateTree();
    int height = 0; 
      if (isBalanced(root,&height)) 
        cout << "true"; 
    else
        cout << "false";  
}
