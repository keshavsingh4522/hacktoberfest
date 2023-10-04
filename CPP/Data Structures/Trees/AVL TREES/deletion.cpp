// deletion in avl tree is not simply
// remoing a node form its position or adjusting
// parent posituoons it also needs to check the balance factor again and re asssemble the tree
#include <iostream>
using namespace std;

class Node
{
public:
    int key, height;
    Node *left;
    Node *right;
    Node(int key) : key(key), height(1), left(NULL), right(NULL) {}
};

class AVL
{
private:
    Node *root;

    int height(Node *N)
    {
        if (!N)
            return 0;
        return N->height;
    }

    int getBalance(Node *N)
    {
        if (!N)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T3 = x->right;

        x->right = y;
        y->left = T3;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node *insert(Node *node, int key)
    {
        if (!node)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    Node *deleteNode(Node *root, int key)
    {
        if (!root)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }

        if (!root)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

public:
    AVL() : root(NULL) {}

    void insert(int key)
    {
        root = insert(root, key);
    }

    void remove(int key)
    {
        root = deleteNode(root, key);
    }
};

int main()
{
    AVL avlTree;

    // Sample insertions
    avlTree.insert(30);
    avlTree.insert(20);
    avlTree.insert(10);
    avlTree.insert(25);
    avlTree.insert(28);
    avlTree.insert(27);
    avlTree.insert(5);

    // Sample deletion
    avlTree.remove(10);
    return 0;
}