#
# @lc app=leetcode id=543 lang=python3
#
# [543] Diameter of Binary Tree
# https://leetcode.com/problems/diameter-of-binary-tree/description/

# @lc code=start
# Definition for a binary tree node.
from typing import Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
    diameters = set()

    def solve(root):
      if not root:
        return 0
      left = solve(root.left)
      right = solve(root.right)
      diameters.add(left+right)
      return max(left, right)+1

    solve(root)
    return max(diameters)

    # @lc code=end
