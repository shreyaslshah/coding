#
# @lc app=leetcode id=46 lang=python3
#
# [46] Permutations
# https://leetcode.com/problems/permutations/description/

# @lc code=start
from typing import List


class Solution:
  def permute(self, nums: List[int]) -> List[List[int]]:
    def solve(remainingNums: List[int], currNums: List[int]):
      if not remainingNums:
        ans.append(currNums)
        return
      for i in range(len(remainingNums)):
        solve(remainingNums[:i]+remainingNums[i+1:], currNums+[remainingNums[i]])

    ans = []
    solve(nums, [])
    return ans
    # @lc code=end
