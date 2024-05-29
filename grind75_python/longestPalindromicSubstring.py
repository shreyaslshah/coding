# https://leetcode.com/problems/longest-palindromic-substring/editorial/

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        ans = [0, 0]
        
        for i in range(n):
            dp[i][i] = True
        
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                ans = [i, i + 1]

        diff = 2
        times = n-2

        while diff <= n-1:
            i = 0
            j = i+diff
            t = times
            while t >= 1:
                if s[i]==s[j] and dp[i+1][j-1]:
                    dp[i][j] = True
                    ans = [i, j]
                t-=1
                i+=1
                j+=1
            diff+=1
            times-=1

        i, j = ans
        return s[i:j + 1]
    
s = Solution()
print(s.longestPalindrome("babad"))