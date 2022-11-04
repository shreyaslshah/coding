// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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

vector<vector<int>> levelOrderBottom(TreeNode *root) {
  vector<vector<int>> ans;
  if (root == NULL) {
    return ans;
  }
  queue<TreeNode *> qu;
  qu.push(root);
  ans.push_back(vector<int>{root->val});
  while (!qu.empty()) {
    int size = qu.size();
    vector<int> a;
    while (size > 0) {
      TreeNode *node = qu.front();
      qu.pop();
      if (node->left) {
        a.push_back(node->left->val);
        qu.push(node->left);
      }
      if (node->right) {
        a.push_back(node->right->val);
        qu.push(node->right);
      }
      size--;
    }
    if (a.size())
      ans.push_back(a);
  }

  for(int i=0; i<ans.size()/2; i++){
    vector<int> temp;
    temp = ans[i];
    ans[i] = ans[ans.size()-1-i];
    ans[ans.size()-1-i] = temp;
  }

  return ans;
}


/***************************************************/



// void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
//     if (!node) return;
//     if (level >= ans.size())
//         ans.push_back({});
//     ans[level].push_back(node->val);
//     levelOrder(ans,node->left,level+1);
//     levelOrder(ans,node->right,level+1);
// }

// vector<vector<int>> levelOrderBottom(TreeNode* root) {
//     vector<vector<int>> ans;
//     levelOrder(ans,root,0);
//     reverse(ans.begin(),ans.end());
//     return ans;
// }