#
# @lc app=leetcode id=416 lang=python3
#
# [416] Partition Equal Subset Sum
# https://leetcode.com/problems/partition-equal-subset-sum/

# @lc code=start
from typing import List


class Solution:
  def canPartition(self, nums: List[int]) -> bool:
    summ = sum(nums)
    if summ % 2 == 1:
      return False
    summ = int(summ/2)
    dp = [[False for _ in range(summ+1)]for _ in range(len(nums)+1)]

    for i in range(len(dp)):
      dp[i][0] = True

    for row in range(1, len(dp)):
      currNum = nums[row-1]
      for col in range(1, len(dp[0])):
        if currNum > col:
          dp[row][col] = dp[row-1][col]
        else:
          dp[row][col] = dp[row-1][col] or dp[row-1][col-currNum]

    return dp[-1][-1]

    # @lc code=end


s = Solution()
print(s.canPartition(nums=[1, 5, 11, 5]))
