#
# @lc app=leetcode id=93 lang=python3
#
# [93] Restore IP Addresses
#

# @lc code=start
from typing import List


class Solution:
  def restoreIpAddresses(self, s: str) -> List[str]:
    ans = []

    def solve(partitions, i, currIP):
      if partitions>4:
        return
      if partitions == 4 and i==len(s):
        ans.append(currIP[:-1])
        return
      
      for j in range(i, i+3):
        if j>=len(s):
          continue
        if int(s[i:j+1])<256 and (s[i]!='0' or i==j):
          solve(partitions+1, j+1, currIP+s[i:j+1]+'.')
    
    solve(0, 0, '')

    return ans

s = Solution()
s.restoreIpAddresses("25525511135")

    # @lc code=end
