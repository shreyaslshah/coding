#
# @lc app=leetcode id=128 lang=python3
#
# [128] Longest Consecutive Sequence
#

# @lc code=start
from typing import List


class Solution:
  def longestConsecutive(self, nums: List[int]) -> int:
    nums = set(nums)
    ans = 0

    for num in nums:
      if num-1 not in nums:
        n = num
        currMax = 0
        while n in nums:
          currMax+=1
          n+=1
        ans = max(ans, currMax)
    
    return ans

    # @lc code=end
