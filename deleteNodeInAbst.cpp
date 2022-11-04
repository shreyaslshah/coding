// https://leetcode.com/problems/delete-node-in-a-bst/

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

// TreeNode *findInSucc(TreeNode *node) {
//   if (node->right == NULL) {
//     return NULL;
//   }
//   TreeNode *inSucc = node->right;
//   if (inSucc->left == NULL) {
//     return node;
//   }
//   while (inSucc->left->left != NULL) {
//     inSucc = inSucc->left;
//   }
//   return inSucc;
// }

// TreeNode *deleteNode(TreeNode *root, int key) {
//   if (root == NULL) {
//     return root;
//   }
//   if (root->val > key) {
//     root->left = deleteNode(root->left, key);
//   } else if (root->val < key) {
//     root->right = deleteNode(root->right, key);
//   } else {
//     TreeNode *inSucc = findInSucc(root);
//     if (inSucc == NULL) {
//       TreeNode *node = root->left;
//       delete root;
//       return node;
//     } else {
//       if (inSucc == root) {
//         root->val = inSucc->right->val;
//         TreeNode *nodeToBeDeleted = root->right;
//         root->right = root->right->right;
//         delete nodeToBeDeleted;
//       } else {
//         root->val = inSucc->left->val;
//         TreeNode *nodeToBeDeleted = inSucc->left;
//         inSucc->left = nodeToBeDeleted->right;
//         delete nodeToBeDeleted;
//       }
//     }
//   }
//   return root;
// }

/***************************************************/

TreeNode *deleteNode(TreeNode *root, int key) {
  if (root)
    if (key < root->val)
      root->left = deleteNode(root->left, key);
    // We recursively call the function until we find the target node
    else if (key > root->val)
      root->right = deleteNode(root->right, key);
    else {
      if (!root->left && !root->right) return NULL;
      // No child condition

      if (!root->left || !root->right)
        return root->left ? root->left : root->right;
      // One child contion -> replace the node with it's child

      // Two child condition using inorder predecessor
      TreeNode *temp = root->left;
      // (or) TreeNode *temp = root->right;
      while (temp->right != NULL) temp = temp->right;
      // (or) while(temp->left != NULL) temp = temp->left;
      root->val = temp->val;
      //(or) root->val = temp->val;
      root->left = deleteNode(root->left, temp->val);
      //(or) root->right = deleteNode(root->right, temp);
    }
  return root;
}