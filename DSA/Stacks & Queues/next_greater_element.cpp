#include <bits/stdc++.h>
using namespace std;

void nextGreaterElement(int arr[],int n,vector<int> &result){
    stack<int> s; // store the indices of the elements.
    // for the last element
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() and arr[s.top()] <= arr[i]) {
            s.pop();
        }
        result[i] = s.empty() ? -1 : arr[s.top()];
        s.push(i);
    }
}


int main(){
	int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> result(n);
    nextGreaterElement(arr,n,result);
    for(int i=0;i<result.size();i++){
    	cout << result[i] << " ";
	}
	return 0;
}
