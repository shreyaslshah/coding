// https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1#
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
  int data;
  Node* left;
  Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
  Node* temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

vector<int> findSpiral(Node* root);

// Function to Build Tree
Node* buildTree(string str) {
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // Create the root of the tree
  Node* root = newNode(stoi(ip[0]));

  // Push the root to the queue
  queue<Node*> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size()) {
    // Get and remove the front of the queue
    Node* currNode = queue.front();
    queue.pop();

    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N") {
      // Create the left child for the current node
      currNode->left = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N") {
      // Create the right child for the current node
      currNode->right = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

int main() {
  string s;
  getline(cin, s);
  Node* root = buildTree(s);

  vector<int> vec = findSpiral(root);
  for (int x : vec)
    cout << x << " ";
  cout << endl;

  return 0;
}

// Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node* root) {
  vector<int> ans;
  if (root == NULL) {
    return ans;
  }
  queue<deque<Node*>> q;
  bool dir = 0;  // 0 - left, 1 - right
  deque<Node*> currLevel;
  currLevel.push_back(root);
  ans.push_back(root->data);
  q.push(currLevel);
  while (!q.empty()) {
    deque<Node*> temp = q.front();
    deque<Node*> nextLevel;
    q.pop();
    while (!temp.empty()) {
      Node* node = temp.back();
      temp.pop_back();
      if (!dir) {
        if (node->left) {
          nextLevel.push_back(node->left);
          ans.push_back(node->left->data);
        }
        if (node->right) {
          nextLevel.push_back(node->right);
          ans.push_back(node->right->data);
        }
      } else {
        if (node->right) {
          nextLevel.push_back(node->right);
          ans.push_back(node->right->data);
        }
        if (node->left) {
          nextLevel.push_back(node->left);
          ans.push_back(node->left->data);
        }
      }
    }
    if (!nextLevel.empty())
      q.push(nextLevel);
    dir = !dir;
  }
  return ans;
}
