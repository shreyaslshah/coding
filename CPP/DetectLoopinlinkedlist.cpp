//https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1#

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int val) {
    data = val;
    next = NULL;
  }
};

void loopHere(Node* head, Node* tail, int position) {
  if (position == 0) return;

  Node* walk = head;
  for (int i = 1; i < position; i++)
    walk = walk->next;
  tail->next = walk;
}

class Solution {
 public:
  // Function to check if the linked list has a loop.
  bool detectLoop(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while (fast != NULL) {
      fast = fast->next;
      // if (fast == slow)
      //   return true;
      if (fast)
        fast = fast->next;
      if (fast == slow)
        return true;
      slow = slow->next;
    }

    return false;
  }
};

// { Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, num;
    cin >> n;

    Node *head, *tail;
    cin >> num;
    head = tail = new Node(num);

    for (int i = 0; i < n - 1; i++) {
      cin >> num;
      tail->next = new Node(num);
      tail = tail->next;
    }

    int pos;
    cin >> pos;
    loopHere(head, tail, pos);

    Solution ob;
    if (ob.detectLoop(head))
      cout << "True\n";
    else
      cout << "False\n";
  }
  return 0;
}
// } Driver Code Ends