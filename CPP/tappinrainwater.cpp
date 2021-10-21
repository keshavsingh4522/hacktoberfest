#include<bits/stdc++.h>
using namespace std;

int trapped_Rainwater(vector<int> v){
    int n = v.size();
    int ans = 0;
    stack<int> st;

    for(int i=0; i<n; i++){
        while(!st.empty() && v[st.top()]<v[i]){
            int curr = st.top();
            st.pop();

            if(st.empty())
                break;
            
            int diff = i-st.top()-1;
            ans += (min(v[st.top()], v[i]) - v[curr]) * diff;
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    int ans = trapped_Rainwater(v);
    cout<<ans<<endl;
    
    return 0;
}
