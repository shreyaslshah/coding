#
# @lc app=leetcode id=113 lang=python3
#
# [113] Path Sum II
#

# @lc code=start
# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
    ans = []

    def solve(node):
      nonlocal ans
      if not node:
        return []
      if not node.left and not node.right:
        if node == root and node.val == targetSum:
          ans.append([node.val])
          return
        return [[node.val]]
      leftPaths = solve(node.left)
      rightPaths = solve(node.right)
      paths = leftPaths+rightPaths
      for path in paths:
        path.append(node.val)
      if node == root:
        for path in paths:
          if sum(path) == targetSum:
            ans.append(path[::-1])
      return paths

    if root:
      solve(root)
    return ans

    # @lc code=end


# class Solution:
#   def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:

#     def dfs(node, cur_path, cur_target):

#         # base case
#       if not node:
#         # empty node or empty tree
#         return

#       # general case

#       # update current path
#       cur_path.append(node.val)

#       # update current target
#       cur_target -= node.val

#       if not node.left and not node.right and cur_target == 0:

#         # current path is valid with wanted targetSum
#           # list is pass-by-reference in Python, so here we have to make a copy of list
#         answer.append(cur_path[::])

#         # undo selection and go back to previous level
#         cur_path.pop()
#         return

#       # solve subproblem in DFS
#       dfs(node.left, cur_path, cur_target)
#       dfs(node.right, cur_path, cur_target)

#       # undo selection and go back to previous level
#       cur_path.pop()
#       return

#     # ------------------------------------------
#     answer = []

#     dfs(root, [], targetSum)

#     return answer
