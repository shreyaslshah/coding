// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* temp;

class Solution {
 public:
  static bool rec(Node* node, int n) {
    if (n != 0) {
      bool ans = rec(node->next, n - 1);
      if (ans == false) {
        return false;
      }
    }
    if (temp->data == node->data) {
      temp = temp->next;
      return true;
    } else {
      return false;
    }
  }
  // Function to check whether the list is palindrome.
  bool isPalindrome(Node* head) {
    Node* a = head;
    int count = 0;
    while (a != NULL) {
      a = a->next;
      count++;
    }
    int n = count / 2;
    a = head;
    for (int i = 0; i < n; i++) {
      a = a->next;
    }
    temp = a;
    return rec(head, ((count % 2) ? count / 2 : count / 2 - 1));
  }
};

// { Driver Code Starts.
/* Driver program to test above function*/
int main() {
  int i, n, l, firstdata;

  struct Node *head = NULL, *tail = NULL;
  cin >> n;
  // taking first data of LL
  cin >> firstdata;
  head = new Node(firstdata);
  tail = head;
  // taking remaining data of LL
  for (i = 1; i < n; i++) {
    cin >> l;
    tail->next = new Node(l);
    tail = tail->next;
  }
  Solution obj;
  cout << obj.isPalindrome(head) << endl;

  return 0;
}

// } Driver Code Ends



// arshia's code

// Node* left;
// bool recursion(Node* right) {
//   if (right == NULL) {
//     return true;
//   }
//   bool ans = recursion(right->next);
//   if (ans == false) {
//     return false;
//   }
//   if (left->data == right->data) {
//     left = left->next;
//     return true;
//   } else {
//     return false;
//   }
// }
// bool isPalindrome(Node* head) {
//   left = head;
//   return recursion(head);
// }