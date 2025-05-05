#
# @lc app=leetcode id=53 lang=python3
#
# [53] Maximum Subarray
# https://leetcode.com/problems/maximum-subarray/description/

# @lc code=start
from typing import List
import sys


class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    localMax = -sys.maxsize
    globalMax = -sys.maxsize

    for n in nums:
      if n>localMax+n:
        localMax = n
      else:
        localMax += n
      globalMax = max(globalMax, localMax)
    
    return globalMax

    # @lc code=end
