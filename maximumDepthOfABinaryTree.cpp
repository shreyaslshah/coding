// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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

class Solution {
 public:
  int height(TreeNode *node) {
    if (node == NULL) {
      return 0;
    }

    int lheight = height(node->left);
    int rheight = height(node->right);

    if (lheight > rheight) {
      return lheight + 1;
    } else {
      return rheight + 1;
    }
  }

  int maxDepth(TreeNode *root) {
    return height(root);
  }
};