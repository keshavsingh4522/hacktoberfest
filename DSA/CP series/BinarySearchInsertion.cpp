#include <iostream>
using namespace std;

class node
{
    public:
        node *left;
        node *right;
        int a;
        node(int x)
        {
            a = x;
            left = NULL;
            right = NULL;
        }
};

node* root;

class BST
{
    public:
        void insert(node* &root, int x)
        {
            if(root == NULL)
            {
                root = new node(x);
                return;
            }
            if(x < root->a)
            {
                insert(root->left, x);
            }
            else
            {
                insert(root->right, x);
            }
        }
        void inorder(node* root)
        {
            if(root == NULL)
            {
                return;
            }
            inorder(root->left);
            cout << root->a << " ";
            inorder(root->right);
        }
};

int main()
{
    BST b;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.insert(root, x);
    }

    cout << "Inorder traversal of the Binary Search Tree" << endl;
    b.inorder(root);
    cout << endl;
    return 0;
    
}