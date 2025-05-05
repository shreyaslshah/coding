#
# @lc app=leetcode id=198 lang=python3
#
# [198] House Robber
#

# @lc code=start
from typing import List


class Solution:

  def rob(self, nums: List[int]) -> int:
    currMax = 0
    for i in range(len(nums)):
      if i>=2:
        currMax = max(currMax, nums[i-2])
      nums[i]+=currMax

    return max(nums)

    # @lc code=end

s = Solution()
print(s.rob([2,7,9,3,1]))