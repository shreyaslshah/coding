#
# @lc app=leetcode id=17 lang=python3
#
# [17] Letter Combinations of a Phone Number
#https://leetcode.com/problems/letter-combinations-of-a-phone-number/

# @lc code=start
from typing import List


class Solution:
  def letterCombinations(self, digits: str) -> List[str]:
    def solve(i, currStr):
      if len(currStr) == len(digits):
        ans.append(currStr)
        return
      for letter in phone[digits[i]]:
        solve(i+1, currStr+letter)

    if not digits:
      return []
    phone = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl",
             "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
    ans = []
    solve(0, '')
    return ans

    # @lc code=end


s = Solution()
print(s.letterCombinations(digits="23"))
