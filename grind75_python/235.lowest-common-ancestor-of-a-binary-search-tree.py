#
# @lc app=leetcode id=235 lang=python3
#
# [235] Lowest Common Ancestor of a Binary Search Tree
# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, x):
    self.val = x
    self.left = None
    self.right = None


class Solution:
  # for BST
  def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
    if not root:
      return None
    if p.val>q.val:
      return self.lowestCommonAncestor(root, q, p)
    if root.val>p.val and root.val<q.val:
      return root
    if root.val==p.val or root.val==q.val:
      return root
    if root.val<p.val and root.val<q.val:
      return self.lowestCommonAncestor(root.right, p, q)
    if root.val>p.val and root.val>q.val:
      return self.lowestCommonAncestor(root.left, p, q)

  # for a BT
  def lowestCommonAncestorForBT(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
    if not root:
      return None
    left = self.lowestCommonAncestorForBT(root.left, p, q)
    right = self.lowestCommonAncestorForBT(root.right, p, q)
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



# class Solution {
# public:
#     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
#         while (root != NULL) {
#             if (p->val < root->val && q->val < root->val) {
#                 root = root->left;
#             } else if (p->val > root->val && q->val > root->val) {
#                 root = root->right;
#             } else {
#                 return root;
#             }
#         }
#         return NULL;
#     }
# };