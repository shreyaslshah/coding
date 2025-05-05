#
# @lc app=leetcode id=105 lang=python3
#
# [105] Construct Binary Tree from Preorder and Inorder Traversal
# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

# @lc code=start
# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
    def solve(l, r):
      nonlocal curr
      if l > r:
        return None
      curr+=1
      node = TreeNode(preorder[curr])
      inorder_idx = inorder.index(preorder[curr])
      node.left = solve(l, inorder_idx-1)
      node.right = solve(inorder_idx+1, r)
      return node

    if not preorder:
      return None
    curr = -1
    return solve(0, len(preorder)-1)


s = Solution()
s.buildTree(preorder=[3, 9, 20, 15, 7], inorder=[9, 3, 15, 20, 7])

# @lc code=end
