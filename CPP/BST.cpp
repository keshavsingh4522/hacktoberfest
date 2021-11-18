// C++ code for recursively inserting a node in BST
// Constructed using structure
// Contributed by Vaibhav Sharma
#include <iostream>
using namespace std;
// Stucture of node
struct node {
	int data;
	node *lchild,*rchild;
};
// Code for recursively inserting in the tree
node* rinsert(node *p,int key)
{
    node *t = NULL;
    if(!p)
    {
        t = new node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key > p->data)
        p->rchild = rinsert(p->rchild,key);
    else if(key < p->data)
        p->lchild = rinsert(p->lchild,key);
    return p;
}
// Traversals for trees
void preorder(node *p) {
	if(p) {
		cout << p->data << " ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void inorder(node *p) {
	if(p) {
		inorder(p->lchild);
		cout << p->data << " ";
		inorder(p->rchild);
	}
}
void postorder(node *p) {
	if(p) {
		postorder(p->lchild);
		postorder(p->rchild);
		cout << p->data << " ";
	}
}
// Menu based for adding in and printing the tree
int main() {
	node* root = NULL;
	int choice,a;
	do {
		cout << "1. Insert" << endl;
		cout << "2. Preorder" << endl;
		cout << "3. Inorder" << endl;
		cout << "4. Postorder" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice) {
			case 1: cout << "Enter value to be inserted: ";
					cin >> a;
					rinsert(root,a);
					cout << "\nValue inserted\n";
					break;
			case 2: cout << "Preorder: ";
					preorder(root);
					cout << "\n";
					break;
			case 3: cout << "Inorder: ";
					inorder(root);
					cout << "\n";
					break;
			case 4: cout << "Postorder: ";
					postorder(root);
					cout << "\n";
					break;
			case 5: exit(0);
			default:cout << "\nInvalid choice\n";
		}
	} while(choice != 5);
	return 0;
}
