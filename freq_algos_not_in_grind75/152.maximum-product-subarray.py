#
# @lc app=leetcode id=152 lang=python3
#
# [152] Maximum Product Subarray
# https://leetcode.com/problems/maximum-product-subarray/description/
# https://www.youtube.com/watch?v=hnswaLJvr6g

# @lc code=start
import sys
from typing import List


class Solution:

  def maxProduct(self, nums: List[int]) -> int:
    # ans is either in prefix or suffix product. when we encounter 0 we make the curr 1 to start fresh.

    ans = max(nums)
    curr = nums[0] if nums[0]!=0 else 1

    for i in range(1, len(nums)):
      num = nums[i]
      if num==0:
        curr = 1
        continue
      curr = curr*num
      ans = max(ans, curr)
    
    curr = nums[-1] if nums[-1]!=0 else 1

    for i in range(len(nums)-2, -1, -1):
      num = nums[i]
      if num==0:
        curr = 1
        continue
      curr = curr*num
      ans = max(ans, curr)
    
    return ans


    # @lc code=end
