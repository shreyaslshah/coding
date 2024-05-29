# https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution:
  def search(self, nums: List[int], target: int) -> int:
    l = 0
    r = len(nums)-1
    m = 0

    while l<=r:
      m = (l+r)//2
      if nums[m]==target:
        return m
      if nums[m]<nums[r]:
        if nums[m]<target<=nums[r]:
          l = m+1
        else:
          r = m-1
      else:
        if nums[l]<=target<nums[m]:
          r = m-1
        else:
          l = m+1
    
    return -1


# https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution:
  def search(self, nums: List[int], target: int) -> int:
    l = 0
    r = len(nums)-1
    m = 0

    while l<=r:
      m = (l+r)//2
      if nums[m]==target:
        return True
      if nums[m]==nums[l]==nums[r]:
        l+=1
        r-=1
        continue
      if nums[m]<=nums[r]:
        if nums[m]<target<=nums[r]:
          l = m+1
        else:
          r = m-1
      else:
        if nums[l]<=target<nums[m]:
          r = m-1
        else:
          l = m+1
    
    return False


# https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution:
  def findMin(self, nums: List[int]) -> int:
    l = 0
    r = len(nums)-1
    m = 0
    ans = 50000
    while l<=r:
      m = (l+r)//2
      if nums[m]<nums[r]:
        ans = min(ans, nums[m])
        r = m-1
      else:
        ans = min(ans, nums[l])
        l = m+1
    
    return ans
      