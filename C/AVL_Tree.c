#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} node;

int max(int a , int b){
    return (a > b)? a:b;
}

node* getNode(int val){
    node* temp = (node *)malloc(sizeof(node));

    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;

    return temp;
}

int getHeight(node* root){
    if(root == NULL){
        return 0;
    }

    return root->height;
}

node* rotateRight(node* root){
    if(root == NULL) return root;

    node* t1 = root->left;
    node* t2 = t1->right;
    
    t1->right = root;
    root->left = t2;

    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    t1->height = 1 + max(getHeight(t1->left),getHeight(t1->right));

    return t1;
}

node* rotateLeft(node* root){
    if(root == NULL) return root;

    node* t1 = root->right;
    node* t2 = t1->left;

    t1->left = root;
    root->right = t2;

    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    t1->height = 1 + max(getHeight(t1->left),getHeight(t1->right));

    return t1;
}

int balanceFactor(node* root){
    if(root == NULL) return 0;

    return (getHeight(root->left) - getHeight(root->right));
}

node* insertNode(node* root , int val){

    node* n = getNode(val);

    if(root == NULL)    return n;

    if(val > root->data){
        root->right = insertNode(root->right,val);
    }
    else{
        root->left = insertNode(root->left,val);
    }

    root->height = 1 + max(getHeight(root->left),getHeight(root->right));

    int bal = balanceFactor(root);

    if(bal > 1 && val < root->left->data){
        return rotateRight(root);
    }

    if(bal > 1 && val > root->left->data){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if(bal < -1 && val > root->right->data){
        return rotateLeft(root);
    }

    if(bal < -1 && val < root->right->data){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}


node* inorderSucc(node* root){
    
    node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

node* deleteNode(node* root , int val){
    if(root == NULL) return root;

    if(val > root->data){
        root->right = deleteNode(root->right,val);
    }
    else if(val < root->data){
        root->left = deleteNode(root->left,val);
    }
    else{

        node* t;

        if(root->left == NULL){
            
            t = root->right;
            free(root);
            return t;
        }
        else if(root->right == NULL){

            t = root->left;
            free(root);
            return t;
        }
        else{
            node* temp = inorderSucc(root->right);

            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }

        if(root == NULL){
            return root;
        }

        root->height = 1  + max(getHeight(root->left),getHeight(root->right));

        int bal = balanceFactor(root);

        if(bal > 1 && balanceFactor(root->left) >= 0){
            return rotateRight(root);
        }

        if(bal > 1 && balanceFactor(root->right) < 0){
            root->left = rotateLeft(root->left);

            return rotateRight(root->right);
        }

        if(bal < -1 && balanceFactor(root->right) <= 0){
            return rotateLeft(root);
        }

        if(bal < -1 && balanceFactor(root->right) > 0){
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

void inorder(node* root){
    if(root == NULL)    return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){

    node* root = NULL;

    root = insertNode(root,1);
    root = insertNode(root,2);
    root = insertNode(root,3);
    root = insertNode(root,4);
    root = insertNode(root,5);
    root = insertNode(root,6);
    root = insertNode(root,7);

    inorder(root);
    puts("");

    root = deleteNode(root,4);
    root = deleteNode(root,1);
    root = deleteNode(root,7);

    inorder(root);
    puts("");

    return 0;
}