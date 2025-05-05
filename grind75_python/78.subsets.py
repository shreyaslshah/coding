#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
# https://leetcode.com/problems/subsets/

# @lc code=start
from typing import List


class Solution:
  def subsets(self, nums: List[int]) -> List[List[int]]:
    def solve(nums, currNums, i):
      if i == len(nums):
        ans.append(currNums)
        return
      solve(nums, currNums + [nums[i]], i+1)
      solve(nums, currNums, i+1)
    
    ans = []
    solve(nums, [], 0)
    return ans
    # @lc code=end
