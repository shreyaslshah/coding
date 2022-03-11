// https://leetcode.com/problems/invert-binary-tree/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
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

TreeNode *invert(TreeNode *node) {
  if (node == NULL) {
    return node;
  }

  TreeNode *temp = node->left;
  node->left = node->right;
  node->right = temp;

  node->left = invert(node->left);
  node->right = invert(node->right);

  return node;
}

TreeNode *invertTree(TreeNode *root) {
  return invert(root);
}