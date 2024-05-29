# https://leetcode.com/problems/binary-search/

import math

class Solution:

  def solve(self, nums, target, l, r):
    if l>r:
      return -1
    m = math.floor((l+r)/2)
    if target == nums[m]:
      return m
    elif target > nums[m]:
      return self.solve(nums, target, m+1, r)
    else:
      return self.solve(nums, target, l, m-1)


  def search(self, nums: List[int], target: int) -> int:
    return self.solve(nums, target, 0, len(nums)-1)