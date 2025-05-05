#
# @lc app=leetcode id=124 lang=python3
#
# [124] Binary Tree Maximum Path Sum
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

  def solve(self, root, ans):
    if not root:
      return 0

    leftSum = self.solve(root.left, ans)
    rightSum = self.solve(root.right, ans)

    ans[0] = max(ans[0], root.val + leftSum + rightSum,
                 root.val, root.val+leftSum, root.val+rightSum)

    return root.val + max(leftSum, rightSum, 0)

  def maxPathSum(self, root: Optional[TreeNode]) -> int:
    ans = [-float('inf')]
    self.solve(root, ans)
    return ans[0]

    # @lc code=end


# class Solution:
#   def maxPathSum(self, root: TreeNode) -> int:
#     max_path = float("-inf")  # placeholder to be updated

#     def get_max_gain(node):
#       nonlocal max_path  # use outer max_path
#       if node is None:
#         return 0

#       # Recursively compute the maximum gain from left and right subtrees
#       gain_on_left = max(get_max_gain(node.left), 0)
#       gain_on_right = max(get_max_gain(node.right), 0)

#       # Max path through the current node
#       current_max_path = node.val + gain_on_left + gain_on_right

#       # Update the global max path if needed
#       max_path = max(max_path, current_max_path)

#       # Return the max gain if continuing the same path
#       return node.val + max(gain_on_left, gain_on_right)

#     get_max_gain(root)  # Starts the recursion chain
#     return max_path
