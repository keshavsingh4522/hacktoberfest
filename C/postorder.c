#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
}; 
struct node *craetenode(int data) 
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void postorder(struct node*root){
    if (root!=NULL){
        postorder(root->right);
        postorder(root->left);
        printf("%d",root->data);
    }
}
int main(int argc, char const *argv[])
{
    //  pre-ordertraversal
    struct node *p = craetenode(4);
    struct node *p1 = craetenode(1);
    struct node *p2 = craetenode(6);
    struct node *p3 = craetenode(5);
    struct node *p4 = craetenode(8);
    // struct node*p craetenode(4);
    // struct node*p craetenode(4);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    postorder(p);
    
    return 0;
}
