#
# @lc app=leetcode id=739 lang=python3
#
# [739] Daily Temperatures
#

# @lc code=start
from typing import List


class Solution:
  def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
    stack = [[temperatures[0], 0, 1]] # temp, idx, warmer days
    ans = [0 for i in range(len(temperatures))]

    for i in range(1, len(temperatures)):
      t = temperatures[i]
      if t<=stack[-1][0]:
        stack.append([t, i, 1])
      else:
        while len(stack)!=0 and t>stack[-1][0]:
          _, idx, warmerDays = stack.pop()
          ans[idx] = warmerDays
          if len(stack)!=0:
            stack[-1][2] += warmerDays
        stack.append([t, i, 1])
    
    return ans

    # @lc code=end

# class Solution:
#     def dailyTemperatures(self, temps):
#         results = [0] * len(temps)
#         stack = []
#         # UPVOTE !
#         for i, temp in enumerate(temps):
#             while stack and temps[stack[-1]] < temp:
#                 index = stack.pop()
#                 results[index] = i - index
#             stack.append(i)

#         return results

# While the stack is not empty and the current temperature is greater than the temperature at the index on the top of the stack:
#   - Update the result for the index at the top of the stack with the difference between the current index and the index on the top of the stack.
#   - Pop the index from the stack.
# Push the current index onto the stack.