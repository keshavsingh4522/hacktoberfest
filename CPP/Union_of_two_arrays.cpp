#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int m,n;

    
    
    cout<<"Enter sizes";
    cin>>m>>n;

    cout<<"Enter first Array Values";
    int a[n],b[m];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"Enter Second array values";
    for(int i=0;i<m;i++)
    cin>>b[i];
    
    sort(a,a+n);
    sort(b,b+m);
    int k=0,u=n;
    for(int i=0;i<n;i++){
        for(int j=k;j<m;j++){
            if(a[i]!=b[j]){
                u++;
            }else{
                k++;
                break;
            }
        }
    }

    cout<<"Wait\n"<<u;

    return 0;

}