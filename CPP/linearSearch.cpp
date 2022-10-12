#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void linearSearch(vector<int> arr,int target){
    
    int result=-100;
    for(int i=0;i<=arr.size();i++){
        if(arr[i]==target){
            result=i;
            break;
            
            
        }
        
       
    }
    if(result==-100){
        cout<<"Given integer is not in array"<<endl;
    }
    else{
        cout<<"given element is in index :"<<result<<endl; 
    }

}

int main(){

    vector<int> arr={5,2,7,3,1};
  
    linearSearch(arr,100);
    

    

    return 0;
}