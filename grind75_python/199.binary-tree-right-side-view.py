#
# @lc app=leetcode id=199 lang=python3
#
# [199] Binary Tree Right Side View
# https://leetcode.com/problems/binary-tree-right-side-view/description/

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
  def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
    if not root:
      return []
    q = deque()
    ans=[]
    q.append(root)

    while q:
      for i in range(len(q)):
        node=q.popleft()
        if i==0:
          ans.append(node.val)
        if node.right:
          q.append(node.right)
        if node.left:
          q.append(node.left)
    
    return ans

    # @lc code=end
