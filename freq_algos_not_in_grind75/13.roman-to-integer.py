#
# @lc app=leetcode id=13 lang=python3
#
# [13] Roman to Integer
#

# @lc code=start
class Solution:
  def romanToInt(self, s: str) -> int:
    d = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }
    ans = d[s[0]]
    for i in range(1, len(s)):
      if d[s[i]]>d[s[i-1]]:
        ans = ans - d[s[i-1]] + d[s[i]] - d[s[i-1]]
      else:
        ans += d[s[i]]
    return ans

    # @lc code=end
