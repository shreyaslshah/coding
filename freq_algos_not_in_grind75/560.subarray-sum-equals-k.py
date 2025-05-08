#
# @lc app=leetcode id=560 lang=python3
#
# [560] Subarray Sum Equals K
#

# @lc code=start
from collections import defaultdict
from typing import List


class Solution:
  def subarraySum(self, nums: List[int], k: int) -> int:
    d = defaultdict(int)
    d[0] = 1

    prefixSum = 0
    ans = 0

    for num in nums:
      prefixSum += num
      if prefixSum-k in d:
        ans += d[prefixSum-k]
      d[prefixSum] += 1

    return ans

    # @lc code=end
