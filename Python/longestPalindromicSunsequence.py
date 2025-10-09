class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        
        # base case
        if s == s[::-1]:
            return len(s)
        
        
        # length of string s
        n = len(s)
        
        # consider another string which is reversed of s,
        # bcz to apply LCS, we need atleast two strings
        t = s[::-1]
        
        # now apply LCS on s, t
        
        dp = [[0 for j in range(n+1)] for i in range(n+1)]
        
        for i in range(1, n+1):
            for j in range(1, n+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                    
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                    
        return dp[n][n]
        
