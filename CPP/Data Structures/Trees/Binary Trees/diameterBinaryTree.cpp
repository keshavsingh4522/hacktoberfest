#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
node* left;
node* right;
};
class bst{
private:
    node* left;node* right;
public:

node* insert(node* root,int k)
{
if(root==NULL)
{
node* temp=new node;
temp->data=k;
temp->left=temp->right=NULL;
return temp;
}
else if(root->data >k)
root->left=insert(root->left,k);
else if(root->data <k)
root->right=insert(root->right,k);
return root;
}
int height(node* root)
{
if(root==NULL)
return 0;
int l=height(root->left);
int r=height(root->right);
return max(l,r)+1;
}
int diameter(node* root)
{
   if(root==NULL)
   return 0;

int l=height(root->left);
int r=height(root->right);
int ld=diameter(root->left);
int rd=diameter(root->right);
int ds=max(ld,rd);
return max( ds,(1+l+r));
}
};

int main()
{
bst b;
node* root=NULL;
root=b.insert(root,1);
b.insert(root,2);
b.insert(root,3);
b.insert(root,4);
b.insert(root,5);
cout<<b.diameter(root);
return 0;



return 0;
}