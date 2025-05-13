#
# @lc app=leetcode id=100 lang=python3
#
# [100] Same Tree
#

# @lc code=start
# Definition for a binary tree node.
from typing import Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    ans = True

    def solve(p, q):
      nonlocal ans
      if not p and not q:
        return
      if (p==None and q!=None) or (p!=None and q==None) or (p.val != q.val):
        ans = False
        return
      solve(p.left, q.left)
      solve(p.right, q.right)
    
    solve(p, q)
    return ans


    # @lc code=end
