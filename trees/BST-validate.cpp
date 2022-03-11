// https://leetcode.com/problems/validate-binary-search-tree/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inTrav(TreeNode *node, bool *ans, long int *prevVal) {
  if (node) {
    inTrav(node->left, ans, prevVal);
    if (*prevVal >= node->val) {
      *ans = false;
      return;
    } else {
      *prevVal = node->val;
    }
    inTrav(node->right, ans, prevVal);
  }
}

bool isValidBST(TreeNode *root) {
  bool ans = true;
  long int prevVal = LONG_MIN;
  inTrav(root, &ans, &prevVal);
  return ans;
}

/*****************************************/

/*
bool isValidBST(TreeNode *root) {
  return isValidBST(root, NULL, NULL);
}

bool isValidBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
  if (!root) return true;
  if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
    return false;
  return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}
*/