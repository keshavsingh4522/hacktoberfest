class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n  = v.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int res = 1;
        for (int i = 0; i < n; i++){
            if (v[i] != v[res - 1]){
                v[res] = v[i];
                res++;
            }
        }
        return res;
    }   
};