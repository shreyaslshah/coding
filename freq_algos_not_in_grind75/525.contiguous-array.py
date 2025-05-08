#
# @lc app=leetcode id=525 lang=python3
#
# [525] Contiguous Array
#

# @lc code=start
from typing import List


class Solution:
  def findMaxLength(self, nums: List[int]) -> int:
    d = dict()
    d[0] = -1
    prefixSum = 0
    ans = 0
    for i in range(len(nums)):
      if nums[i]==0:
        prefixSum-=1
      else:
        prefixSum+=1
      if prefixSum in d:
        ans = max(ans, i-d[prefixSum])
      else:
        d[prefixSum] = i
    return ans

    # @lc code=end
