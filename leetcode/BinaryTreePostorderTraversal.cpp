// https://leetcode.com/problems/binary-tree-postorder-traversal/

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

/***********************************************************************/

// using 2 stacks
vector<int> postorderTraversal2(TreeNode *root) {
  vector<int> ans;

  if (root == NULL) {
    return ans;
  }

  stack<TreeNode *> stck1;
  stack<TreeNode *> stck2;
  TreeNode *current = root;

  while (!(current == NULL && stck1.empty())) {
    while (current != NULL) {
      stck2.push(current);
      stck1.push(current);
      current = current->right;
    }

    current = stck1.top();
    stck1.pop();
    current = current->left;
  }

  while (!stck2.empty()) {
    ans.push_back(stck2.top()->val);
    stck2.pop();
  }

  return ans;
}

/***********************************************************************/

// using 1 stack
vector<int> postorderTraversal(TreeNode *root) {
  vector<int> ans;

  if (root == NULL) {
    return ans;
  }

  stack<TreeNode *> stck;
  TreeNode *current = root;

  while (!(current == NULL && stck.empty())) {
    while (current != NULL) {
      stck.push(current);
      current = current->left;
    }
    if (stck.top()->right) {
      current = stck.top()->right;
    } else {
      auto temp = stck.top();
      ans.push_back(temp->val);
      stck.pop();
      while (!stck.empty() && stck.top()->right == temp) {
        temp = stck.top();
        ans.push_back(temp->val);
        stck.pop();
      }
    }
  }

  return ans;
}