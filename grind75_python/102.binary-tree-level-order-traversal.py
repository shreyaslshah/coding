#
# @lc app=leetcode id=102 lang=python3
#
# [102] Binary Tree Level Order Traversal
# https://leetcode.com/problems/binary-tree-level-order-traversal/description/

# @lc code=start
# Definition for a binary tree node.
from collections import deque
from typing import List, Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    if not root:
      return []
    q = deque()
    ans=[]
    q.append(root)

    while q:
      lvl = []
      for _ in range(len(q)):
        node=q.popleft()
        lvl.append(node.val)
        if node.left:
          q.append(node.left)
        if node.right:
          q.append(node.right)
      ans.append(lvl)
    
    return ans
        
# @lc code=end

