/*Given the root of a binary tree, return the 
lowest common ancestor of its deepest leaves.*/
 
//Input:-
 
/*  0
   / \ 
  1   3
   \
    2
*/

//Output:- 2

/*Explanation:- The deepest leaf node in the tree is 2, 
                the lca of one node is itself.*/
#include<bits/stdc++.h>
using namespace std;

 // Definition for a binary tree node.
 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    pair<TreeNode*,int> solve(TreeNode* root){
        if(root==NULL){
            return {root,0};
        }
        auto l=solve(root->left);
        auto r=solve(root->right);
        //if the left level == right level then the lca is itself, as it is the deepest level.
        if(l.second==r.second){
            return {root,l.second+1};
        }
        //if left level is greater then left child is the lca
        //vice-versa
        if(l.second>r.second){
            return {l.first,l.second+1};
        }
        return {r.first,r.second+1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).first;
    }
};
//Printing in preorder
void preorder(TreeNode* root){
	 if(root==NULL){
	 	return ;
	 }
	 cout<<root->val<<" ";
	 preorder(root->left);
	 preorder(root->right);
	 
}
int main(){
   	struct TreeNode* root=new TreeNode(0);
	root->left=new TreeNode(1);
	root->right=new TreeNode(3);
	root->left->right=new TreeNode(2);
	Solution obj;
	struct TreeNode* node=obj.lcaDeepestLeaves(root);
	preorder(node);
  return 0;
}

