// https://leetcode.com/problems/reverse-nodes-in-even-length-groups/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// A linked list node
struct Node {
  int data;
  struct Node *next;
};

void append(struct Node **head, int node_data) {
  /* 1. create and allocate node */
  struct Node *newNode = new Node;

  struct Node *last = *head; /* used in step 5*/

  /* 2. assign data to the node */
  newNode->data = node_data;

  /* 3. set next pointer of new node to null as its the last node*/
  newNode->next = NULL;

  /* 4. if list is empty, new node becomes first node */
  if (*head == NULL) {
    *head = newNode;
    return;
  }

  /* 5. Else traverse till the last node */
  while (last->next != NULL)
    last = last->next;

  /* 6. Change the next of last node */
  last->next = newNode;
  return;
}

void displayList(struct Node *node) {
  // traverse the list to display each node
  while (node != NULL) {
    cout << node->data << "-->";
    node = node->next;
  }

  if (node == NULL)
    cout << "null";
}

struct Node *reverse(struct Node *head) {
  struct Node *prev = NULL;
  struct Node *curr = head;

  while (curr) {
    struct Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

Node *reverseBetween(Node *head, int m, int n) {
  if (m == n)
    return head;
  Node *revs = NULL, *revs_prev = NULL;
  Node *revend = NULL, *revend_next = NULL;

  // Find values of above pointers.
  int i = 1;
  Node *curr = head;
  while (curr && i <= n) {
    if (i < m)
      revs_prev = curr;

    if (i == m)
      revs = curr;

    if (i == n) {
      revend = curr;
      revend_next = curr->next;
    }

    curr = curr->next;
    i++;
  }
  revend->next = NULL;

  // Reverse linked list starting with
  // revs.
  revend = reverse(revs);

  // If starting position was not head
  if (revs_prev)
    revs_prev->next = revend;

  // If starting position was head
  else
    head = revend;

  revs->next = revend_next;
  return head;
}

struct Node *reverseEvenLengthGroups(struct Node *head) {
  int count = 1;
  int glen = 1;
  int gno = 1;
  int start = 1;
  int end = 1;
  struct Node *curr = head;

  while (curr != NULL && curr->next != NULL) {
    while (glen > 0) {
      curr = curr->next;
      glen--;
      end++;
      if (curr == NULL) {
        break;
      }
    }
    if ((count - glen) % 2 == 0) {
      head = reverseBetween(head, start, end - 1);
    }
    start = start + count;
    end = start;
    count++;
    glen = count;
  }
  return head;
}

int main() {
  struct Node *head = NULL;

  append(&head, 5);
  append(&head, 2);
  append(&head, 6);
  append(&head, 3);
  append(&head, 9);

  displayList(head);
  cout << endl;

  head = reverseEvenLengthGroups(head);

  displayList(head);

  return 0;
}