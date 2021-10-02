/*
Two Mirror Trees 

Easy Accuracy: 49.96% Submissions: 26278 Points: 2
Given a Two Binary Trees, write a function that returns true if one is mirror of other, else returns false.
MirrorTree1            

Example 1:

Input:
T1:     1     T2:     1
      /   \         /   \
     2     3       3     2
Output: 1
Example 2:

Input:
T1:     10      T2:   10
       /  \          /  \
      20  30        20  30
     /  \          /  \
    40   60       40  60
Output: 0

Your Task:
You don't need to take input. Just complete the function areMirror() that takes root node of two tree as parameter and returns true, if one is the 
mirror of other else returns false. (The driver's code print 1 if the returned value is true, otherwise 0)
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes<= 10000
-1000 <= Data of a node<= 1000
*/

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int areMirror(Node *, Node *);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);

        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);

        cout << areMirror(root1, root2) << "\n";
    }
    return 0;
}// } Driver Code Ends


/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
int areMirror(Node* a, Node* b) {
// Your code here
if(a == b && a == NULL)
return 1;

if(a && b && a->data == b->data)
return (areMirror(a->left, b->right) && areMirror(a->right, b->left));

return 0;

}
