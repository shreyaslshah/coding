#
# @lc app=leetcode id=22 lang=python3
#
# [22] Generate Parentheses
#

# @lc code=start
from typing import List


class Solution:
  def generateParenthesis(self, n: int) -> List[str]:
    ans = []

    def solve(idx, curr):
      if idx==n*2-1:
        ans.append(curr+')')
        return
      if curr.count('(')==curr.count(')'):
        solve(idx+1, curr+'(')
      elif curr.count('(')<n and curr.count('(')>curr.count(')'):
        solve(idx+1, curr+'(')
        solve(idx+1, curr+')')
      elif curr.count('(')==n:
        solve(idx+1, curr+')')
      

    
    solve(0, '')
    return ans

    # @lc code=end

# - The idea is to add ')' only after valid '('
# - We use two integer variables left & right to see how many '(' & ')' are in the current string
# - If left < n then we can add '(' to the current string
# - If right < left then we can add ')' to the current string 

# def generateParenthesis(self, n: int) -> List[str]:
# 	def dfs(left, right, s):
# 		if len(s) == n * 2:
# 			res.append(s)
# 			return 

# 		if left < n:
# 			dfs(left + 1, right, s + '(')

# 		if right < left:
# 			dfs(left, right + 1, s + ')')

# 	res = []
# 	dfs(0, 0, '')
# 	return res