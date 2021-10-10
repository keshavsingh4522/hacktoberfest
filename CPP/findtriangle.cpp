/*You are given the length of three sides a, b, and c respectively for a triangle.
 If these three sides can form an Equilateral Triangle then print 1, 
 If these three sides can form an Isosceles Triangle then print 2, 
 if these three sides can form a Scalene Triangle then print 3, 
 otherwise print −1.

 Sample Input:
 4 4 4
 
 Output:
 1

 Sample Input
 3 3 2

 Sample Output 
 2

 Sample Input:
 2 4 6

 Sample Output:
 3
 */


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[3];
	for(int i=0; i<=2; i++){
	    cin>>arr[i];
	}
	int n = sizeof(arr) / sizeof(arr[0]);
 
    sort(arr, arr + n);

	
	
	if(arr[0]+arr[1]-arr[2]>0){
    	if(arr[0]==arr[1] && arr[1]==arr[2]){
    	    cout<<"1";
    	}
    	else if(((arr[0]==arr[1]) || (arr[1]==arr[2]) || (arr[0]==arr[2]))){
    	    cout<<"2";
    	}
    	else if(arr[0]!=arr[1] && arr[1]!=arr[2]){
    	    cout<<"3";
    	}
	}
	else{
	    cout<<"-1";
	}
}
