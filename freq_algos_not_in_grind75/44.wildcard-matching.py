#
# @lc app=leetcode id=44 lang=python3
#
# [44] Wildcard Matching
# https://leetcode.com/problems/wildcard-matching/description/

# @lc code=start
# DP
class Solution:
  def isMatch(self, s: str, p: str) -> bool:
    dp = [[False]*(len(p)+1) for i in range(len(s)+1)]
    dp[0][0] = True
    for j in range(1, len(p)+1):
      if p[j-1] == '*':
        dp[0][j] = dp[0][j-1]

    for i in range(1, len(s)+1):
      for j in range(1, len(p)+1):
        if s[i-1] == p[j-1] or p[j-1] == '?':
          dp[i][j] = dp[i-1][j-1]
        elif p[j-1] == '*':
          #take 0, 1, or more matches
          dp[i][j] = dp[i][j-1] or dp[i-1][j] or dp[i-1][j-1]

    return dp[len(s)][len(p)]


# @lc code=end

s = Solution()
print(s.isMatch("ab", "?*"))
