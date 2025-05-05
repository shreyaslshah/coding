#
# @lc app=leetcode id=139 lang=python3
#
# [139] Word Break
# https://leetcode.com/problems/word-break/description/

# @lc code=start
from typing import List


class Solution:
  def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    dp = [False for _ in range(len(s)+1)]
    dp[len(s)] = True

    for i in range(len(s)-1, -1, -1):
      for word in wordDict:
        if len(word) <= len(s)-i and word == s[i: i+len(word)]:
          dp[i] = dp[i+len(word)]
        if dp[i]:
          break
    
    return dp[0]
          # @lc code=end

s = Solution()
print(s.wordBreak('abcd', ["a","abc","b","cd"]))