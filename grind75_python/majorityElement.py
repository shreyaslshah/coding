# https://leetcode.com/problems/majority-element/

class Solution:
  def majorityElement(self, nums: List[int]) -> int:
    count = 0
    currMajority = nums[0]

    for num in nums:
      if num == currMajority:
        count += 1
      else:
        if count:
          count -= 1
        else:
          currMajority = num
          count = 1

    return currMajority


# This approach (boyer moore voting algorithm) works because:

# We simply know that the majority element has a frequency greater than half of the total elements.

# So , the value of count > 0.

# But whenever it becomes 0 , it means that till now the majority element has either not occured , or if it has then the its frequency is equal to the sum of frequency of rest of the others. So , the next element will be the majority element till now . But eventually by the end , the final answer will always be the majority element of the array , as when the "count" becomes 0 for the final time , the next element will be the majority element.
