#
# @lc app=leetcode id=70 lang=python3
#
# [70] Climbing Stairs
# https://leetcode.com/problems/climbing-stairs/description/

# @lc code=start
class Solution:
  def climbStairs(self, n: int) -> int:
    # it's fibonacci

    if n <= 2:
      return n
    
    first = 1
    second = 2

    ans = 0

    for i in range(3, n+1):
      ans = first+second
      first = second
      second = ans
    
    return ans
  
    # @lc code=end
