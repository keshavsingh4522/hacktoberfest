#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};
Node* root = NULL;

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to insert item in a tree
void insertItem(int item)
{
    Node *newnode = newNode(item);
    if(!root) {
        root = newnode;
        return;
    }
    Node *cur, *prev;
    cur = root;
    while(cur!= NULL) {
        prev = cur;
        if(cur->data > item)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if(prev->data > item)
        prev->left = newnode;
    else
        prev->right = newnode;
}

vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *t=q.front();
        while(t){
            ans.push_back(t->data);
            if(t->left)
                q.push(t->left);
            t=t->right;
        }
        q.pop();
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        insertItem(arr[i]);
    }
    vector<int> ans = diagonal(root);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}
