#
# @lc app=leetcode id=206 lang=python3
#
# [206] Reverse Linked List
#https://leetcode.com/problems/reverse-linked-list/description/

# @lc code=start
# Definition for singly-linked list.
from typing import Optional


class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:
  def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if not head:
      return head
    prev = None
    curr = head
    next = head.next

    while curr:
      curr.next = prev
      prev = curr
      curr = next
      if next:
        next = next.next

    return prev


# @lc code=end




# class Solution {
# public:
#     ListNode* reverseList(ListNode* head) {

#         ListNode* prev = NULL;
#         ListNode* curr = head;

#         while(curr != NULL){
#             ListNode* forward = curr->next;
#             curr->next = prev;
#             prev = curr;
#             curr = forward;
            
#         }
#         return prev;
#     }
# };