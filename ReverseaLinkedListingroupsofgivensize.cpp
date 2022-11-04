// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

// { Driver Code Starts
using namespace std;

struct node {
  int data;
  struct node* next;

  node(int x) {
    data = x;
    next = NULL;
  }
};

/* Function to print linked list */
void printList(struct node* node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

class Solution {
 public:
  struct node* reverse(struct node* head, int k) {
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;
    int count = 0;

    /*reverse first k nodes of the linked list */
    while (curr and count < k) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      count++;
    }

    /* next is now a pointer to (k+1)th node, Recursively call for the list starting from current. And make rest of the list as next of first node */
    if (curr)
      head->next = reverse(curr, k);

    /* prev is new head of the input list */
    return prev;
  }
};

// { Driver Code Starts.

/* Drier program to test above function*/
int main(void) {
  struct node* head = NULL;
  struct node* temp = NULL;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    if (i == 0) {
      head = new node(value);
      temp = head;
    } else {
      temp->next = new node(value);
      temp = temp->next;
    }
  }

  int k;
  cin >> k;

  Solution ob;
  head = ob.reverse(head, k);
  printList(head);

  return (0);
}

// } Driver Code Ends