
//https://leetcode.com/submissions/detail/1086734676/

class Solution {
public:
    string reverseOnlyLetters(string s) {
        for(int i=0,j=s.size()-1;i<=j;){
            if((isalpha(s[i]))&&(isalpha(s[j]))){
                swap(s[i],s[j]);
                i++,j--;
            }
            else if(!(isalpha(s[i]))) i++;
            else j--;
            // cout<<i<<" "<<j<<" "<<s<<endl;
        }
        return s;
    }
};
