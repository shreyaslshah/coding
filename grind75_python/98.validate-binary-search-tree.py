#
# @lc app=leetcode id=98 lang=python3
#
# [98] Validate Binary Search Tree
# https://leetcode.com/problems/validate-binary-search-tree/description/

# @lc code=start
# Definition for a binary tree node.
from typing import Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def isValidBST(self, root: Optional[TreeNode]) -> bool:

    def inorder(root: Optional[TreeNode]):
      nonlocal prev
      if not root:
        return True
      left = inorder(root.left)
      if root.val > prev:
        prev = root.val
      else:
        return False
      right = inorder(root.right)
      return left and right
    
    prev = -2**31-1
    return inorder(root)
  



    # @lc code=end


# class Solution {

# bool isPossible(TreeNode* root, long long l, long long r){
#     if(root == nullptr)  return true;
#     if(root->val < r and root->val > l)
#         return isPossible(root->left, l, root->val) and 
#                                 isPossible(root->right, root->val, r);
#     else return false;
# }

# public:
#     bool isValidBST(TreeNode* root) {
#         long long int min = -1000000000000, max = 1000000000000;
#         return isPossible(root, min, max);
#     }
# };