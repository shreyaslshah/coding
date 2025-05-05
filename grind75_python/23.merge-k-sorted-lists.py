#
# @lc app=leetcode id=23 lang=python3
#
# [23] Merge k Sorted Lists
# https://leetcode.com/problems/merge-k-sorted-lists/description/

# @lc code=start
# Definition for singly-linked list.
from typing import List, Optional
import queue


class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:
  def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
    pq = queue.PriorityQueue()
    curr: ListNode = None
    ans = None
    # for unique comparison in pq. needed for python when val is equal and python cannot compare two list nodes
    count = 0

    for i in range(len(lists)):
      if lists[i]:
        pq.put((lists[i].val, count, lists[i]))
        count += 1

    while pq.qsize():
      val, c, node = pq.get()
      if curr:
        curr.next = node
        curr = curr.next
      else:
        curr = node
        ans = curr
      if node.next:
        pq.put((node.next.val, count, node.next))
        count += 1

    return ans

    # @lc code=end


s = Solution()
print(s.mergeKLists([ListNode(1)]))
