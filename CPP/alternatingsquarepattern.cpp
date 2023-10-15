/*You're given a number N. Print the first N lines of the below-given pattern.

1 2 3 4 5
10 9 8 7 6
11 12 13 14 15
20 19 18 17 16
21 22 23 24 25
30 29 28 27 26
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int i1=0;
	
	
	for(int i=0; i<n; i++){
	    if(i%2==0){
	        for(int j=(10*i1)+1; j<=(i+1)*5; j++){
	            cout<<j<<" ";
	        }
	        i1++;
	        cout<<endl;
	    }
	    else{
	        for(int k=(i+1)*5; k>=(5*i)+1; k--){
	            cout<<k<<" ";
	        }
	        cout<<endl;
	    }
	}
}