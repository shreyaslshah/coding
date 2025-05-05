#
# @lc app=leetcode id=383 lang=python3
#
# [383] Ransom Note
# https://leetcode.com/problems/ransom-note/description/

# @lc code=start
from collections import defaultdict


class Solution:
  def canConstruct(self, ransomNote: str, magazine: str) -> bool:
    d = defaultdict(int)
    for letter in magazine:
      d[letter] += 1
    for letter in ransomNote:
      if d[letter]>0:
        d[letter]-=1
      else:
        return False
    return True
# @lc code=end
