#include<bits/stdc++.h>
using namespace std;

// Defined node of binary tree
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left=NULL;
        right=NULL;
    }
};

// Function to get Left View of BT
vector<int> LeftView(Node* root){
    vector<int> Ans;
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        int size=Q.size();
        vector<int> temp;
        while(size--){
            Node* node=Q.front();
            Q.pop();
            temp.push_back(node->data);
            if(node->left)
            Q.push(node->left);
            if(node->right)
            Q.push(node->right);
        }
        Ans.push_back(temp[0]);
    }
    return Ans;
}

// Function to take input and contruct Tree
Node* CreateDummyTree(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    return root;
}

int main(){
    Node* root=CreateDummyTree();
    
    vector<int> Ans = LeftView(root);
    
    // Print left view....
    for(auto ans:Ans)
    cout<<ans<<" ";
}