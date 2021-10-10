#include<iostream>
#include<stdlib.h> 
using namespace std;

int main(){
    int order;
    cout<<"Enter the order of the matrix"<<endl;
    cin>>order;

    int index = (4 + (3*(order - 2)));

    int arr[index];

    cout<<"Input "<<index<<" number of elements"<<endl;
    for(int i=0 ; i<index ; i++){
        cin>>arr[i];
    }

    int row, col;
    int indexkeep = 0;
    cout<<"Output"<<endl<<endl;
    for(row=1 ; row<=order ; row++){
        for(col=1 ; col<=order ; col++){
        	int diff = row - col;
            if(abs(diff)<=1){
                cout<<arr[indexkeep]<<" ";
                indexkeep++;}
            else
                cout<<"0 ";
            }
        cout<<endl;
        }
    
    
return 0;
}
