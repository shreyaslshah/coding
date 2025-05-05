#
# @lc app=leetcode id=72 lang=python3
#
# [72] Edit Distance
# https://leetcode.com/problems/edit-distance/description/

# explanation needed: https://www.youtube.com/watch?v=XYi2-LPrwm4

# @lc code=start
class Solution:
  def minDistance(self, word1: str, word2: str) -> int:
    dp = [[0 for _ in range(len(word1)+1)] for _ in range(len(word2)+1)]

    for i in range(len(word1)):
      dp[-1][i] = len(word1)-i

    for i in range(len(word2)):
      dp[i][-1] = len(word2)-i

    for i in range(len(word2)-1, -1, -1):
      for j in range(len(word1)-1, -1, -1):
        if word1[j] == word2[i]:
          dp[i][j] = dp[i+1][j+1]
        else:
          dp[i][j] = 1 + min(dp[i+1][j+1], dp[i+1][j], dp[i][j+1])

    return dp[0][0]
    # @lc code=end
