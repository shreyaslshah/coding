// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
};

void append(struct ListNode **head, int node_val) {
  struct ListNode *newNode = new ListNode;
  struct ListNode *last = *head;
  newNode->val = node_val;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  while (last->next != NULL)
    last = last->next;
  last->next = newNode;
  return;
}

void displayList(struct ListNode *ListNode) {
  while (ListNode != NULL) {
    cout << ListNode->val << " => ";
    ListNode = ListNode->next;
  }
  if (ListNode == NULL)
    cout << "null";
}

list<int> ll;
unordered_multimap<int, list<int>::iterator> map;

ListNode *removeZeroSumSublists(ListNode *head) {
  ListNode *temp = head;
  while (temp != NULL) {
    ll.push_back(temp->val);
    temp = temp->next;
  }

  int prefixSum = 0;
  auto it = ll.begin();
  while (it != ll.end()) {
    prefixSum += *it;
    if (prefixSum == 0) {
      auto iter = ll.begin();
      auto mapIter = map.find((*iter));
      int sum = *iter;
      while (iter != it) {
        map.erase(sum);
        iter = ll.erase(iter);
        sum += *iter;
      }
      map.erase(sum);
      it = ll.erase(it);
    } else if (map.count(prefixSum)) {
      auto iter = map.find(prefixSum)->second;
      auto mapIter = map.find(prefixSum);
      int sum = (*mapIter).first + (*(++iter));
      while (iter != it) {
        map.erase(sum);
        iter = ll.erase(iter);
        sum += *iter;
      }
      // map.erase(sum);
      it = ll.erase(it);
    } else {
      map.insert({prefixSum, it});
      it++;
    }
  }

  struct ListNode *result = NULL;
  for (auto it = ll.begin(); it != ll.end(); it++) {
    append(&result, *it);
  }

  return result;
}

int main() {
  struct ListNode *head = NULL;
  append(&head, 2);
  append(&head, 2);
  append(&head, -2);
  append(&head, 1);
  append(&head, -1);
  append(&head, -1);
  // append(&head, 5);
  // append(&head, -6);
  // displayList(head);
  struct ListNode *result = removeZeroSumSublists(head);
  displayList(result);
}