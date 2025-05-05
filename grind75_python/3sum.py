# https://leetcode.com/problems/3sum/

from typing import List


class Solution:
  def threeSum(self, nums: List[int]) -> List[List[int]]:
    ans = []
    nums.sort()
    for index in range(len(nums) - 2):
      if index == 0 or nums[index - 1] != nums[index]:
        l = index + 1
        r = len(nums) - 1
        while l < r:
          if nums[l] + nums[r] + nums[index] > 0:
            r -= 1
          elif nums[l] + nums[r] + nums[index] < 0:
            l += 1
          else:
            ans.append([nums[index], nums[l], nums[r]])
            l += 1
            r -= 1
            while l+1 < len(nums) and nums[l] == nums[l-1]:
              l += 1
            while r-1 > index and nums[r] == nums[r+1]:
              r -= 1
    return ans


s = Solution()
print(s.threeSum([-2, 0, 1, 1, 2]))
