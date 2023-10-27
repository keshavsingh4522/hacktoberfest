
#include <iostream>

using namespace std;

int main()
{
    int n,row,col;
    cout<<"enter";
    cin>>n;
    for(row=0;row<n;row ++){
        for(col=0;col<n-row-1;col++){
            cout<<"  ";
        }
        for(col=0;col<2*row+1;col++){
            if(row==0){
                cout<<" *";
            }
            else if(col==0||col==2*row){
                cout<<" *";
            }
            else{
                cout<<"  ";
            }
        }
        

        cout<<endl;
    }
    for(row=0;row<n;row ++){
        for(col=0;col<row;col++){
            cout<<"  ";
        }
        for(col=0;col<2*(n-row)-1;col++){
            if(row==n){
                cout<<" *";
            }
            else if (col==0|| col==2*n-2*row-2){
                cout<<" *";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
