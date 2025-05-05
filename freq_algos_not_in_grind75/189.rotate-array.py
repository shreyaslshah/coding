#
# @lc app=leetcode id=189 lang=python3
#
# [189] Rotate Array
#

# @lc code=start
from typing import List


class Solution:
  def rotate(self, nums: List[int], k: int) -> None:
    n = len(nums)
    k %= n  # Handle cases where k > n

    # Helper function to reverse a portion of the array
    def reverse(start: int, end: int):
      while start < end:
        nums[start], nums[end] = nums[end], nums[start]
        start += 1
        end -= 1

    # Step 1: Reverse the entire array
    reverse(0, n - 1)
    # Step 2: Reverse the first k elements
    reverse(0, k - 1)
    # Step 3: Reverse the rest
    reverse(k, n - 1)

      
# @lc code=end

s = Solution()
s.rotate([1,2,3,4,5,6,7], 3)