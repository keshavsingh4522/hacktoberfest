#include<bits/stdc++.h>
using namespace std;

struct node {
   int data;
   struct node *leftChild;
   struct node *rightChild;
};

long long kthLargestLevelSum(struct node* root, int k) {
    vector<vector<int>>v;
    int i,n;
    if(!root)return -1;        
    queue<struct node*>q;
    priority_queue<long long>pq;
    q.push(root);
    while(!q.empty()){
        n=q.size();
        long long sum=0;
        for(i=0;i<n;i++){
            struct node* x = q.front();
            q.pop();
            sum+=x->data;
            if(x->leftChild)q.push(x->leftChild);
            if(x->rightChild)q.push(x->rightChild);
        }
        pq.push(sum);
    }
    if(pq.size()<k)return -1;
    k=k-1;
    while(k--)pq.pop();
    return pq.top();
}

//insertion
struct node *root = NULL;
void insert(int data){
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;
   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;
      while(1) {
         parent = current;

         //go to left of the tree
         if(data < parent->data) {
            current = current->leftChild;

            //insert to the left
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }//go to right of the tree
         else {
            current = current->rightChild;

            //insert to the right
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }
   }
}

int main(){
   int i,n,k;
   vector<int> vec;
   cout<<"Enter the no of nodes:";
   cin>>n;
   cout<<"kth largest number:";
   cin>>k;
   cout<<"Enter elements in a tree";
   for(i = 0; i < n; i++){
       int x;
       cin>>x;
       vec.push_back(x);
   }
   for(int i=0 ;i<vec.size();i++){
        insert(vec[i]);
   }
   printf("\nans: ");
    cout<<kthLargestLevelSum(root,k);
   return 0;
}