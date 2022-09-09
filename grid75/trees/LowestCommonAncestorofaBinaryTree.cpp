// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) {
      return NULL;
    }
    if (root == p or root == q) {
      return root;
    }
    TreeNode* a = lowestCommonAncestor(root->left, p, q);
    TreeNode* b = lowestCommonAncestor(root->right, p, q);
    if (!a and !b) {
      return NULL;
    } else if (a and b) {
      return root;
    } else {
      return a ? a : b;
    }
  }
};