// https://leetcode.com/problems/clone-graph/

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  unordered_map<int, Node*> visited;
  Node* cloneGraph(Node* node) {
    if(!node){
      return node;
    }
    if (visited.find(node->val) == visited.end()) {
      Node* newNode = new Node(node->val);
      visited.insert({newNode->val, newNode});
      for (int i = 0; i < node->neighbors.size(); i++) {
        newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
      }
      return newNode;
    } else {
      return visited.find(node->val)->second;
    }
  }
};