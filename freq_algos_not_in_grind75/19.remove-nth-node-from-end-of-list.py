#
# @lc app=leetcode id=19 lang=python3
#
# [19] Remove Nth Node From End of List
#

# @lc code=start
# Definition for singly-linked list.
from typing import Optional


class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:
  def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
    ans = head
    slow = fast = head

    for i in range(n):
      fast = fast.next
    
    # if the node to remove is the first node
    if not fast:
      return ans.next
    
    while fast.next:
      slow = slow.next
      fast = fast.next
    
    slow.next = slow.next.next
    return ans
    
# Use two pointers: one goes ahead, the other follows.
# Think of them as two runners on a track:
# fast gets a head start (n steps).
# Then both start moving at the same pace.
# So when fast reaches the end, slow is exactly n nodes from the end — just before the node to remove.


    # @lc code=end
