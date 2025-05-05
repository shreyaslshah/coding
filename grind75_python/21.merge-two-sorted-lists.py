#
# @lc app=leetcode id=21 lang=python3
#
# [21] Merge Two Sorted Lists
#https://leetcode.com/problems/merge-two-sorted-lists/description/

# @lc code=start
# Definition for singly-linked list.
from typing import Optional


class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:
  def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
    dummy = temp = ListNode(0)
    while l1 != None and l2 != None:  # 1

      if l1.val < l2.val:  # 2
        temp.next = l1  # 3
        l1 = l1.next  # 4
      else:
        temp.next = l2
        l2 = l2.next
      temp = temp.next
    temp.next = l1 or l2  # 5
    return dummy.next  # 6

  # @lc code=end
