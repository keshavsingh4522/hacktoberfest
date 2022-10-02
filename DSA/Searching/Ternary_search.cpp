#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;


class searrch{
      public:
       int serBinIt(int arr[],int x,int lo,int hi)
       {
           int mid;
             while(lo<=hi)
             {
                  mid = lo + (hi-lo)/2;

                   if(arr[mid] == x) return mid;
                   else if(arr[mid] > x) hi = mid-1;
                   else lo = mid+1;
             }
             return -1;
       }
       int serBinRec(int arr[],int x,int lo,int hi)
       {
              if(lo>hi) return -1;
              int mid = lo + (hi-lo)/2;

              if(arr[mid] == x) return mid;
              else if(arr[mid] > x) return serBinRec(arr,x,lo,mid-1);
                 return serBinRec(arr,x,mid+1,hi);
       }
         int serLin(int arr[],int x,int lo,int hi)
         {
              for(int i=lo;i<=hi;i++)
              {
                 if(arr[i] == x) return i;
              }
              return -1;
         }
                  // recursive approach
         int terSerRec(int arr[],int x,int l,int h)
         {
              if(l>h) return -1;

                 int mid1 = l + (h - l) / 3;
                 int mid2 = h - (h - l) / 3;

                  if(arr[mid1] == x) return mid1;
                  else if(arr[mid2] == x) return mid2;

                  else if(arr[mid1]>x) return terSerRec(arr,x,l,mid1-1);
                  else if(arr[mid2]<x) return terSerRec(arr,x,mid2+1,h);
                  else return terSerRec(arr,x,mid1+1,mid2-1);
         }
     
                // iterative approach
            
         int terSerIt(int arr[],int x,int l,int h)
         {
                 while(l<=h)
                 { 
                    int mid1 = l + (h - l) / 3;
                     int mid2 = h - (h - l) / 3;
                       
                 if(arr[mid1] == x) return mid1;
                  else if(arr[mid2] == x) return mid2;

                  else if(arr[mid1]>x) h = mid1-1;
                  else if(arr[mid2]<x) l = mid2+1;
                  else l = mid1+1,h = mid2-1;
                 }
                 return -1;
         }

};
int main()
{
   //  #ifndef ONLINE_JUDGE
   //  freopen("i_p.txt", "r", stdin);
   //  freopen("o_p.txt", "w", stdout);
   //  #endif
    int n; cin>>n;
        int arr[n];

        for(int i=0;i<n;i++) cin>>arr[i];
     int x; cin>>x;
        searrch a;
        cout<<a.serLin(arr,x,0,n-1)<<"\n";

        sort(arr,arr+n);
        cout<<a.serBinIt(arr,x,0,n-1)<<"\n";

         cout<<a.serBinRec(arr,x,0,n-1)<<"\n";

         cout<<a.terSerRec(arr,x,0,n-1)<<"\n";

         cout<<a.terSerIt(arr,x,0,n-1)<<"\n";
return 0;
}
