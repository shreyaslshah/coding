#
# @lc app=leetcode id=42 lang=python3
#
# [42] Trapping Rain Water
#https://leetcode.com/problems/trapping-rain-water/

# @lc code=start
from typing import List


class Solution:
  def trap(self, height: List[int]) -> int:
    l = 0
    r = len(height)-1
    maxl ,maxr = height[0], height[-1]
    ans = 0

    while l < r:
      if height[l] < height[r]:
        l += 1
        water = min(maxl, maxr)-height[l]
      else:
        r-=1
        water= min(maxl, maxr)-height[r]
      ans += water if water > 0 else 0
      maxl, maxr = max(maxl, height[l]), max(maxr, height[r])
    
    return ans



  def trap_(self, height: List[int]) -> int:
    leftMax = []
    rightMax = []

    currMax = 0
    for i in range(len(height)):
      leftMax.append(currMax)
      currMax = max(currMax, height[i])
    currMax = 0
    for i in range(len(height)-1, -1, -1):
      rightMax.append(currMax)
      currMax = max(currMax, height[i])
    rightMax.reverse()

    ans = 0
    for i in range(len(height)):
      water = min(leftMax[i], rightMax[i])-height[i]
      ans += water if water > 0 else 0

    return ans

    # @lc code=end


s = Solution()
print(s.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))
