#
# @lc app=leetcode id=662 lang=python3
#
# [662] Maximum Width of Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
from collections import defaultdict, deque
import sys
from typing import Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
    q = deque()
    q.append((root, 0))  # node, index
    ans = 0

    while len(q) > 0:
      size = len(q)
      maxIndex = -sys.maxsize
      minIndex = sys.maxsize
      lvlMinIdx = q[0][1]
      for _ in range(size):
        node, index = q.popleft()
        index -= lvlMinIdx
        maxIndex = max(maxIndex, index)
        minIndex = min(minIndex, index)
        if node.left:
          q.append((node.left, 2*index))
        if node.right:
          q.append((node.right, 2*index + 1))
      ans = max(ans, maxIndex-minIndex+1)
    
    return ans

    # @lc code=end
