#
# @lc app=leetcode id=236 lang=python3
#
# [236] Lowest Common Ancestor of a Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, x):
    self.val = x
    self.left = None
    self.right = None


class Solution:
  def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
    if not root:
      return None
    left = self.lowestCommonAncestor(root.left, p, q)
    right = self.lowestCommonAncestor(root.right, p, q)
    if root.val == q.val and (left or right):
      return root
    elif root.val == p.val and (left or right):
      return root
    elif left and right:
      return root
    elif left and not right:
      return left
    elif right and not left:
      return right
    elif root.val == q.val or root.val == p.val:
      return root

# @lc code=end
