#
# @lc app=leetcode id=876 lang=python3
#
# [876] Middle of the Linked List
#https://leetcode.com/problems/middle-of-the-linked-list/description/

# @lc code=start
# Definition for singly-linked list.
from typing import Optional


class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:
  def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if not head.next:
      return head
    single = head
    double = head

    while True:
      single = single.next
      double = double.next
      if double:
        double = double.next
      else:
        return single
      if not double or not double.next:
        return single

    # @lc code=end
