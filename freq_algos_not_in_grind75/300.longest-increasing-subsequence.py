#
# @lc app=leetcode id=300 lang=python3
#
# [300] Longest Increasing Subsequence
# https://leetcode.com/problems/longest-increasing-subsequence/

# @lc code=start
from typing import List


class Solution:
  def lengthOfLIS(self, nums: List[int]) -> int:
    arr = [1 for _ in range(len(nums))]

    for i in range(len(nums)-1, -1, -1):
      for j in range(i+1, len(nums)):
        if nums[i]<nums[j]:
          arr[i] = max(arr[i], 1+arr[j])
    
    return max(arr)


    # @lc code=end
