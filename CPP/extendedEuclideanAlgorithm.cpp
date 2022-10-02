
      //using pointers
#include<iostream>
#define ll long long
#define REP(a,n)  for(long long int i=a;i<n;i++)
using namespace std;
int myfunc(int a ,int b,int *x ,int *y){
    if(b==0){
           *x = 1;
           *y = 0;
          return a;
    }
    int x1  , y1;
    int gcd =  myfunc(b , a%b , &x1 , &y1);
     *x = y1;
     *y = x1 - (a/b)*y1;
     return gcd;
}
int main()
{
   int a ,b;
   int x ,y;
   cin>>a>>b;
     int gcd = myfunc(a,b,&x,&y);
     cout<<"gcd = "<<gcd<<endl;
       cout<<"x = "<<x<<"  y = "<<y;
return 0;
}

/*
   using object and class
   #include<bits/stdc++.h>
 using namespace std;
   class numbers{
         public:
         int x, y ,g;
   };
   numbers extendedEuclidAlgorithm(int a, int b){
         if(b==0){
               numbers ans;
               ans.x=1;
               ans.y=0;
               ans.g=a;
               return ans;
         }
         numbers smallans = extendedEuclidAlgorithm(b,a%b);
         numbers ans;
          ans.x = smallans.y;
          ans.g = smallans.g;
          ans.y = smallans.x - (a/b)*smallans.y;
          return ans;

   }
   signed main(){
      int a ,b;
        cout<<"enter both the numbers: ";
          cin>>a>>b;
          numbers ans = extendedEuclidAlgorithm(a,b);
           cout<<"x = "<<ans.x<<" , y = "<<ans.y<<" , gcd = "<<ans.g<<endl;
            cout<<a<<"*"<<ans.x<<" + "<<b<<"*"<<ans.y<<" = "<<ans.g<<endl;
         return 0;
   }
*/
