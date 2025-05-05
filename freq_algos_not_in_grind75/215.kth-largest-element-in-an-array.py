#
# @lc app=leetcode id=215 lang=python3
#
# [215] Kth Largest Element in an Array
# https://leetcode.com/problems/kth-largest-element-in-an-array/description/

# @lc code=start
from typing import List


class Solution:
  def findKthLargest(self, nums: List[int], k: int) -> int:

    def quickSelect(l, r):
      pivot = nums[r]
      j = l

      for i in range(l, r):
        if nums[i]<=pivot:
          nums[i], nums[j] = nums[j], nums[i]
          j+=1
      
      nums[r], nums[j] = nums[j], nums[r]

      if j == len(nums)-k: return nums[j]
      elif j < len(nums)-k: return quickSelect(j+1, r)
      else: return quickSelect(l, j-1)
    
    return quickSelect(0, len(nums)-1)


    # @lc code=end

s = Solution()
# print(s.findKthLargest())