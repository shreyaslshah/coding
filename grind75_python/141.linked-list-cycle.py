#
# @lc app=leetcode id=141 lang=python3
#
# [141] Linked List Cycle
#https://leetcode.com/problems/linked-list-cycle/description/

# @lc code=start
# Definition for singly-linked list.
from typing import Optional


class ListNode:
  def __init__(self, x):
    self.val = x
    self.next = None


class Solution:
  def hasCycle(self, head: Optional[ListNode]) -> bool:
    slow = head
    fast = head

    while True and slow and fast:
      slow = slow.next
      fast = fast.next
      if fast:
        fast = fast.next
      else:
        return False
      if slow == fast:
        return True

    # @lc code=end
