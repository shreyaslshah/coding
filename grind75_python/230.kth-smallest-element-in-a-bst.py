#
# @lc app=leetcode id=230 lang=python3
#
# [230] Kth Smallest Element in a BST
# https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

# @lc code=start
# Definition for a binary tree node.
from typing import Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
    def inorder(root: Optional[TreeNode]):
      nonlocal count, ans
      if not root or count>k:
        return
      left = inorder(root.left)
      count+=1
      if count == k:
        ans = root.val
        return
      right = inorder(root.right)

    count = 0
    ans = None
    inorder(root)
    return ans

    # @lc code=end
