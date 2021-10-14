// question-- https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    void gp(int open,int close,int n,vector<string> &ans,string s)
    { if(open==n and close==n)
       {
          ans.push_back(s);return;
       }
        if(open<n)
        {
            s+='(';
            gp(open+1,close,n,ans,s);
            s.pop_back();
            }
       if(close<n and close<open)
       {
           s+=')';
           gp(open,close+1,n,ans,s);
           s.pop_back();
           }
    }
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
        gp(0,0,n,ans,"");
        return ans;
    }
};
