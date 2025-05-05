#
# @lc app=leetcode id=31 lang=python3
#
# [31] Next Permutation
# https://www.youtube.com/watch?v=JDOXKqF60RQ

# @lc code=start
from typing import List


class Solution:
  def nextPermutation(self, nums: List[int]) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """

    for i in range(len(nums)-2, -1, -1):
      swap = None
      idxToSwap = None
      for j in range(i+1, len(nums)):
        if nums[j]>nums[i] and (swap==None or nums[j]<swap):
          swap = nums[j]
          idxToSwap = j
      if idxToSwap:
        nums[i], nums[idxToSwap] = nums[idxToSwap], nums[i]
        nums[i+1:] = sorted(nums[i+1:])
        return

    
    nums.sort()


# @lc code=end

s = Solution()
print(s.nextPermutation([3,2,1]))