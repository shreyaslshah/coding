// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
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

vector<int> preorderTraversal(TreeNode *root) {
  vector<int> ans;

  if (root == NULL) {
    return ans;
  }

  stack<TreeNode *> stck;
  TreeNode *current = root;

  while (!(current == NULL && stck.empty())) {
    while (current != NULL) {
      ans.push_back(current->val);
      stck.push(current);
      current = current->left;
    }

    current = stck.top();
    stck.pop();
    current = current->right;
  }
  return ans;
}