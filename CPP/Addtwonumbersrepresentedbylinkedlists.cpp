// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Linked list Node */
struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

struct Node* buildList(int size) {
  int val;
  cin >> val;

  Node* head = new Node(val);
  Node* tail = head;

  for (int i = 0; i < size - 1; i++) {
    cin >> val;
    tail->next = new Node(val);
    tail = tail->next;
  }

  return head;
}

void printList(Node* n) {
  while (n) {
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

class Solution {
 public:
  static Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }
  // Function to add two numbers represented by linked list.
  struct Node* addTwoLists(struct Node* first, struct Node* second) {
    first = reverse(first);
    second = reverse(second);

    Node* temp = NULL;
    Node* ans;

    int carry = 0;
    int val = 0;

    while (first or second) {
      val = (((first ? first->data : 0) + (second ? second->data : 0)) + carry);
      carry = (val >= 10) ? 1 : 0;
      val = val % 10;

      Node* node = new Node(val);

      if (temp == NULL) {
        temp = node;
        ans = temp;
      } else {
        temp->next = node;
        temp = temp->next;
      }

      if (first)
        first = first->next;
      if (second)
        second = second->next;
    }

    if(carry){
      Node* node = new Node(carry);
      temp->next = node;
    }

    ans = reverse(ans);

    return ans;
  }
};

// { Driver Code Starts.

int main() {
  int n, m;

  cin >> n;
  Node* first = buildList(n);

  cin >> m;
  Node* second = buildList(m);
  Solution ob;
  Node* res = ob.addTwoLists(first, second);
  printList(res);

  return 0;
}
// } Driver Code Ends