class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        
        int mx=0, n=h.size();
        
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i == n || h[st.top()] >= h[i])){
                int ht = h[st.top()];
                st.pop();
                int wd = st.empty()?i:(i-st.top()-1);
                int ar = ht*wd;
                if(ar > mx) mx = ar;                
            }
            st.push(i);
        }
        return mx;
    }
};
