#
# @lc app=leetcode id=25 lang=python3
#
# [25] Reverse Nodes in k-Group
#

# @lc code=start
# Definition for singly-linked list.
from typing import Optional


class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:

  def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

    # check if k nodes are there
    curr = head
    j = k
    while curr and j > 0:
      curr = curr.next
      j -= 1

    if j == 0:
      prev = None
      curr = head
      groupHead = head

      for _ in range(k):
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next

      groupHead.next = self.reverseKGroup(next, k)
      return prev

    else:
      return head

    # @lc code=end
