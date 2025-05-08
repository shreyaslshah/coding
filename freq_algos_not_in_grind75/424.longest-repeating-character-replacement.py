#
# @lc app=leetcode id=424 lang=python3
#
# [424] Longest Repeating Character Replacement
#

# @lc code=start
from collections import defaultdict


class Solution:
  def characterReplacement(self, s: str, k: int) -> int:
    left = 0
    d = defaultdict(int)
    ans = 0

    for right in range(len(s)):
      d[s[right]] += 1
      while (right-left+1)-max(d.values()) > k:
        d[s[left]] -= 1
        left += 1
      if (right-left+1)-max(d.values()) <= k:
        ans = max(ans, right-left+1)

    return ans

    # @lc code=end
