#
# @lc app=leetcode id=328 lang=python3
#
# [328] Odd Even Linked List
#

# @lc code=start
# Definition for singly-linked list.
from typing import Optional


class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:
  def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if not head or not head.next or not head.next.next:
      return head

    prev = ans = head
    curr = head.next
    next = head.next.next

    oddIndicesHead = currOddIndices = ListNode()

    while True:
      currOddIndices.next = curr
      curr.next = None
      currOddIndices = currOddIndices.next
      prev.next = next

      if not next or not next.next:
        break

      prev = next
      curr = prev.next
      next = curr.next

    if prev.next:
      prev = prev.next
    prev.next = oddIndicesHead.next

    return ans

    # @lc code=end


class Solution:
  def oddEvenList(self, head: ListNode) -> ListNode:
      ## RC ##
      ## LOGIC : START WITH BASIC EVEN AND ODD POSITIONS, FOR NEXT ODD APPEND EVENS NEXT AND FOR NEXT EVEN APPEND ODDS NEXT ##

      ## TIME COMPLEXITY : O(N) ##
      ## SPACE COMPLEXITY : O(1) ##

    if (not head):
      return head
    odd = head
    even = head.next
    evenHead = even
    while (even and odd and even.next and odd.next):
      odd.next = even.next
      odd = odd.next
      even.next = odd.next
      even = even.next
    odd.next = evenHead
    return head
