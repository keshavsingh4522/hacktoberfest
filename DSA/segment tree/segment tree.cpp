#include<bits/stdc++.h>
using namespace std;



int getSum(int helper[],int index,int l,int r,int l1,int r1)
{
    if(l>l1 || r<r1)
        return 0;
    if(l>=l1 && r<=r1)
        return helper[index];

    int mid=l+(r-l)/2;
    return getSum(helper,2*index+1,l,mid,l1,r1)+getSum(helper,2*index+2,mid+1,r,l1,r1);


}

void  solve(int helper[],int index,int l,int r,int pre[])
{
    if(l==0)
        helper[index]=pre[r];
    else
        helper[index]=pre[r]-pre[l-1];
    if(l==r)
        return;
    int mid=l+(r-l)/2;
   
    solve(helper,2*index+1,l,mid,pre);
    solve(helper,2*index+2,mid+1,r,pre);


}
void update(int helper[],int index,int l,int r,int diff,int i)
{
    if(!(i>=l && i<=r))
        return;
    helper[index]=helper[index]+diff;
    if(r>l){
    int mid=l+(r-l)/2;
    update(helper,2*index+1,l,mid,diff,i);
    update(helper,2*index+2,mid+1,r,diff,i);
    }
    else
    return;
}
void constructSegTree(int pre[],int n){
   
    int len;
    float p=log2(n);
    int k=ceil(p);
    len=2*pow(2,k)-1;
    int helper[len];
    memset(helper,0,sizeof(helper));
    solve(helper,0,0,n-1,pre);
    for(int i=0;i<len;i++)
      cout<<helper[i]<<" ";
    cout<<endl;
  //cout<<endl<<getSum(helper,0,0,n-1,0,1)<<endl;
    update(helper,0,0,n-1,5,1);
    for(int i=0;i<len;i++)
      cout<<helper[i]<<" ";
}

int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   {
    cin>>arr[i];
   }
   int pre[n];
   pre[0]=arr[0];
   for(int i=1;i<n;i++)
   {
      pre[i]=pre[i-1]+arr[i];  
   }
for(int i=0;i<n;i++)
   {
    cout<<pre[i]<<" ";
   }
   cout<<endl;
   constructSegTree(pre,n);

    return 0;
}