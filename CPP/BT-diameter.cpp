// https://leetcode.com/problems/diameter-of-binary-tree/

// diameter is nothing but the max values of (leftheight+rheight+1) for each node
// so, we can compute it along with the height function


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

int height(TreeNode *node, int *ans) {
  if (node == NULL) {
    return 0;
  }

  int lheight = height(node->left, ans);
  int rheight = height(node->right, ans);

  // compute the diameter as well, as we go through each node
  *ans = max(*ans, lheight + rheight + 1);  

  return max(lheight, rheight) + 1;
}

int diameter(TreeNode *node) {
  if (node == NULL) {
    return 0;
  }

  int ans = INT_MIN;
  height(node, &ans);
  return ans;
}

int diameterOfBinaryTree(TreeNode *root) {
  return diameter(root);
}
