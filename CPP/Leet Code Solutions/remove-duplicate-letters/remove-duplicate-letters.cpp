class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        string str;
        vector<int> count(26);
        vector<bool> used(26);
        for(auto i : s)
        {
            count[i - 'a']++;
        }
        for(auto i : s)
        {
            count[i - 'a']--;
            if(!used[i - 'a'])
            {
                while(str.length() > 0 && i < str.back() && count[str.back() - 'a'] > 0)
                {
                    used[str.back() - 'a'] = false;
                    str.pop_back();
                }
                str.push_back(i);
                used[i-'a'] = true;
            }
        }
        return str;
    }
};
