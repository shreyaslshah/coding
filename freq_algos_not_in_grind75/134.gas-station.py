#
# @lc app=leetcode id=134 lang=python3
#
# [134] Gas Station
#

# @lc code=start
class Solution:
  def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
    if sum(cost) > sum(gas):
      return -1
    
    curr_gas = 0
    ans = 0

    for i in range(len(gas)):
      curr_gas = curr_gas + gas[i] - cost[i]
      if curr_gas<0:
        ans = i+1
        curr_gas = 0

    return ans
    
    


# @lc code=end
