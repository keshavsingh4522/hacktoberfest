// Create Find_Majority_Elements
/*
Find Majority Elements
You have to given an array A of size N.
Find all the elements which appear more than floor(N/3) times in the given array.
There is a condition that you have to do your job in O(N) time complexity and O(1) space complexity.
Input Format
First line contains N ->No. of elements in the array
Second line has N integers denoting the elements of the array A ie A1,A2,A3…….AN.
Constraints
1<=N<=10^7  
0<=Ai<=10^9
Output Format
Print a single line containing all the majority elements occurring more than floor(N/3) times.
If there is no majority element then just print "No Majority Elements".
Sample Input
8
2 2 3 1 3 2 1 1 
Sample Output
1 2
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElements(vector<int> v){
 
 int element1 = v[0];
 int count1=1;

 int element2 = 0;
 int count2 = 0;

 for(int i=0; i<v.size(); i++){
     if(element1==v[i]){
         count1++;
     }
     else if(element2==v[i]){
         count2++;
     }
     else if (count1==0){
         element1=v[i];
         count1= 1;
     }
     else if (count2==0){
         element2=v[i];
         count2 = 1;
     }
     else {
         count1--;
         count2--;
     }
    }
 
 //iterate and find thatt element1 and element2 ka count n/3 ho
 count1 = count2 = 0;
 for(int i=0; i<v.size(); i++){
     if (v[i]== element1) count1++;
     else if (v[i] == element2) count2++;
 }
 vector<int> majority;
 if (count1>v.size()/3){
     majority.push_back(element1);}
 if ( count2> v.size()/3){
     majority.push_back(element2);
  }
  return majority;
}
int main(){
    int n;
    cin>>n;
    
    vector<int> v;
    int x;
    for(int i =0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }
   vector<int> majority;
   majority= majorityElements(v);
    if(majority.size()==0){
        cout<<"No majority element found";
    }
    else{
        for(int i =0; i<majority.size(); i++)
        {cout<<majority[i]<<" ";}
    }
    return 0;
}