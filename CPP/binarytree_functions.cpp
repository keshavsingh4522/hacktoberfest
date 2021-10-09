#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data, hd;
    Node* left, *right;
};

Node* newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void insertLevelOrder(Node *root, int key){
    if(root == NULL){
        Node *newN = newNode(key);
        root = newN;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
        }
        else{
            Node *newN = newNode(key);
            temp->left = newN;
            return;
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
        else{
            Node *newN = newNode(key);
            temp->right = newN;
            return;
        }
    }
    return;
}

void printLevelOrder(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
    return;
}

void deleteDeepest(Node *root, Node *d_node){
    queue<Node *> q;
    Node *temp;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left){
            if(temp->left == d_node){
                temp->left = NULL;
                delete(d_node);          //freeing memory
            }
            else{
                q.push(temp->left);
            }
        }
        if(temp->right){
            if(temp->right == d_node){
                temp->right = NULL;
                delete(d_node);          //freeing memory
            }
            else{
                q.push(temp->right);
            }
        }
    }
    return;
}

void deletion(Node *root, int key){
    Node *temp, *key_node;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data == key){
            key_node = temp;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    int x = temp->data;
    deleteDeepest(root, temp);
    key_node->data = x;
}

void inorder(struct Node* temp) 
{ 
    if (!temp) 
        return; 
    inorder(temp->left); 
    cout << temp->data << " "; 
    inorder(temp->right); 
}

bool findPath(Node* root, vector<int>& path, int k){
    if(root==NULL){
        return false;
    }
    
    path.push_back(root->data);
    if(root->data == k){
        return true;
    }
    if((root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k))){
        return true;
    }
    path.pop_back();
    return false;
}

int findLCA(Node* root, int n1, int n2){
    vector<int> path1, path2;
    if(!findPath(root, path1, n1) || !findPath(root, path2, n2)){
        return -1;
    }
    int i;
    for(i = 0; i<path1.size() && i<path2.size(); i++){
        if(path1[i]!=path2[i]){
            break;
        }
    }
    return path1[i-1];
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1+max(height(root->left), height(root->right));
}

int diameter(Node *root){
    if(root == NULL){
        return 0;
    }
    int l_height = height(root->left);
    int r_height = height(root->right);
    int l_diameter = diameter(root->left);
    int r_diameter = diameter(root->right);
    return max((1 + l_height + r_height), max(l_diameter, r_diameter));
}

void leftViewUtil(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    Node* temp;
    while(!q.empty()){
        temp = q.front();
        if(temp){
            cout<<temp->data<<"  ";
            while(temp != NULL){
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                q.pop();
                temp = q.front();
            }
            q.push(NULL);
        }
        q.pop();
        
    }
}

void rightViewUtil(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    Node *temp, *prev;
    while(!q.empty()){
        temp = q.front();
        if(temp){
            while(temp){
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                prev = temp;
                q.pop();
                temp = q.front();
            }
            cout<<prev->data<<"  ";
            q.pop();
            q.push(NULL);
        }
        else{
            q.pop();
        }
    }
}

void topViewUtil(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    root->hd = 0;
    map<int, int> m;
    int hd = 0;
    q.push(root);
    cout<<"The top view of the tree is : ";
    Node *temp;
    while(!q.empty()){
        temp = q.front();
        hd = temp->hd;
        if(m.find(hd) == m.end()){
            m[hd] = temp->data;
        }
        if(temp->left){
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
        if(temp->right){
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
        q.pop();
        temp = q.front();
    }
    for(auto itr = m.begin(); itr!= m.end(); itr++){
        cout<<itr->second<<"  ";
    }
    return;
}

void bottomViewUtil(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    int hd = 0;
    root->hd = 0;
    map<int, int> m;
    q.push(root);
    Node* temp = q.front();
    cout<<"The bottom view of the tree is : ";
    while(!q.empty()){
        hd = temp->hd;
        m[hd] = temp->data;
        if(temp->left){
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
        if(temp->right){
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
        q.pop();
        temp = q.front();
    }
    for(auto itr : m){
        cout<<itr.second<<"  ";
    }
    return;
}

int main(){
    /* Constructed binary tree is 
             1
            / \
           2   3
          / \
         4   5
    */
    Node* root = newNode(1);
    root->left     = newNode(2);
    root->right     = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    bottomViewUtil(root);

    return 0;
}
