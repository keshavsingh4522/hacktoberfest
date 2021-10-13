#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *child[26];
    bool isend;
    TrieNode()
    {

        for(int i=0;i<26;i++)
            child[i]=NULL;
        isend=false;
    };
};
TrieNode *head=new TrieNode();
void insert(string &s)
{
    TrieNode* curr=head;
    for(int i=0;i<s.length();i++)
    {
       if(curr->child[s[i]-'a']==NULL)
        curr->child[s[i]-'a']=new TrieNode();
       if(i==0)
        head=curr;
       curr=curr->child[s[i]-'a'];
    }
    curr->isend=1;
}
int search(string &s)
{
    TrieNode *start=head;
    for(int i=0;i<s.length();i++)
    {
        if(start->child[s[i]-'a']==NULL)
            return 0;
        start=start->child[s[i]-'a'];
    }
    return start->isend;
}
bool isempty(TrieNode *root)
{
    for(int i=0;i<26;i++)
    {
        if(root->child[i]!=NULL)
            return 0;
    }
    return 1;
}
TrieNode *deletekey(string &s,TrieNode *root,int i){

  if(!root) return NULL;
  if(i==s.length())
  {
    root->isend==false;
    if(isempty(root))
    {
        delete(root);
        root=NULL;
    }
    return root;
  }

  int index=s[i]-'a';
  root->child[index]=deletekey(s,root->child[index],i+1);

if(isempty(root) && root->isend==false)
{
    delete(root);
    root=NULL;
 
}  
  return root;
}


int main(){
   // cout<<"Enter the number of query::1 for insert and 2 for search"<<endl;
    int n;
    cin>>n;
   
    for(int i=0;i<n;i++)
    {
        int q;
        cin>>q;//1 for insert and 2 for search
         string s;
             cin>>s;
        if(q==1)
        {
             //cout<<"Enter string"<<endl;
           
             insert(s);    
             cout<<"done"<<endl;      
        }
        else if(q==2)
        {
             
          cout<<search(s)<<endl;
        }
        else
        {
           
            deletekey(s,head,0);
            cout<<"deleted"<<endl;
        }
    }
    return 0;
}