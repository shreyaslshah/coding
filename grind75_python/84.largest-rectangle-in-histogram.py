#
# @lc app=leetcode id=84 lang=python3
#
# [84] Largest Rectangle in Histogram
# https://leetcode.com/problems/largest-rectangle-in-histogram/description/

# @lc code=start
from typing import List


class Solution:
  def largestRectangleArea(self, heights: List[int]) -> int:
    stack = []
    ans = 0

    for i, height in enumerate(heights):
      if not stack or height >= stack[-1][1]:
        stack.append((i, height))
      else:
        start = i
        while stack and height < stack[-1][1]:
          ans = max(ans, (i-stack[-1][0])*stack[-1][1])
          start = stack[-1][0]
          stack.pop()
        stack.append((start, height))
    
    while stack:
      ans = max(ans, (len(heights)-stack[-1][0])*stack[-1][1])
      stack.pop()
    
    return ans


    # @lc code=end

s = Solution()
print(s.largestRectangleArea([2,4]))