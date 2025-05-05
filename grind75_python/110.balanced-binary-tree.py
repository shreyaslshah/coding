#
# @lc app=leetcode id=110 lang=python3
#
# [110] Balanced Binary Tree
# https://leetcode.com/problems/balanced-binary-tree/description/

# @lc code=start
# Definition for a binary tree node.
from typing import Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def isBalanced(self, root: Optional[TreeNode]) -> bool:
    def solve(root: Optional[TreeNode]):
      nonlocal ans
      if not root:
        return 0
      l_height = solve(root.left)
      r_height = solve(root.right)
      if abs(l_height-r_height) > 1 and ans == True:
        ans = False
      return max(l_height, r_height)+1
    
    ans = True
    solve(root)
    return ans

    # @lc code=end
