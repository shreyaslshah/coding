// https://leetcode.com/problems/balanced-binary-tree/

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

int height(TreeNode *node, bool *ans) {
  if (node == NULL || *ans == false) {
    return 0;
  }

  int lheight = height(node->left, ans);
  if (*ans == false) {
    return 0;
  }

  int rheight = height(node->right, ans);
  if (*ans == false) {
    return 0;
  }

  if (abs(lheight - rheight) > 1) {
    *ans = false;
    return 0;
  }

  return max(lheight, rheight) + 1;
}

bool isBalanced(TreeNode *root) {
  bool ans = true;
  height(root, &ans);
  return ans;
}


/************************************************/

// int dfsHeight(TreeNode *root) {
//   if (root == NULL) return 0;

//   int leftHeight = dfsHeight(root->left);
//   if (leftHeight == -1) return -1;
//   int rightHeight = dfsHeight(root->right);
//   if (rightHeight == -1) return -1;

//   if (abs(leftHeight - rightHeight) > 1) return -1;
//   return max(leftHeight, rightHeight) + 1;
// }
// bool isBalanced(TreeNode *root) {
//   return dfsHeight(root) != -1;
// }