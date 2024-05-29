# https://leetcode.com/problems/sort-colors/

from typing import List

class Solution:

  def sortColors(self, nums: List[int]) -> None:
    l = 0
    r = len(nums)-1
    curr = 0

    while curr<=r:
      if nums[curr] == 1:
        curr+=1
      elif nums[curr]==0:
        nums[curr] = nums[l]
        nums[l] = 0
        l+=1
        curr = l
      else:
        nums[curr] = nums[r]
        nums[r] = 2
        r-=1
    
nums = [2,0,1]
s = Solution()
s.sortColors(nums)
print(nums)


    