# https://leetcode.com/problems/combination-sum/

from typing import List

class Solution:

  def solve(self, i, curr, currSum, target, nums, ans):
    if currSum==target:
      ans.append(curr.copy())
      return
    
    elif currSum>target or i>=len(nums):
      return
    
    else:
      curr.append(nums[i])
      self.solve(i, curr, currSum+nums[i], target, nums, ans)
      curr.pop()
      self.solve(i+1, curr, currSum, target, nums, ans)
      return

  def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    ans = []
    self.solve(0, [], 0, target, candidates, ans)
    return ans
  
s = Solution()
print(s.combinationSum([2,3,6,7], 7))