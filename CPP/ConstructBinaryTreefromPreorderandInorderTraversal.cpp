// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <bits/stdc++.h>
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
  unordered_map<int, int> map;
  int i = 0;
  TreeNode *solve(vector<int> &preorder, int start, int end) {
    if (start > end) {
      return NULL;
    }
    TreeNode *node = new TreeNode(preorder[i]);
    i++;
    int pos = map[node->val];
    node->left = solve(preorder, start, pos - 1);
    node->right = solve(preorder, pos + 1, end);
    return node;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      map.insert({inorder[i], i});
    }
    return solve(preorder, 0, inorder.size() - 1);
  }
};