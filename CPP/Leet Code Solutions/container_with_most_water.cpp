//Question: https://leetcode.com/problems/container-with-most-water/
//Time compexity: O(size of vector) i.e O(n)
//we need to find the any 2 bars ai, aj, which hold most water together with x-axis.
#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int>& h) {
        int i=0;
        int j=h.size()-1;
        int maxarea=0;
        while(i<j){
            maxarea=max(maxarea,min(h[i],h[j])*(j-i));
            if(h[i]<h[j])
                i++;
            else
                j--;
        }
        return maxarea;
 }
int main() {
    int n;
    cin>>n;
    vector<int>h(n);
    for(int i=0;i<n;i++){
        cin>>h[i]; 
    }
    cout<<maxArea(h)<<endl;
    return 0;
}
