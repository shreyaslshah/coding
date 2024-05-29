# https://leetcode.com/problems/clone-graph/description/

# Definition for a Node.
from typing import Deque, Dict, Optional
from collections import deque


class Node:
  def __init__(self, val=0, neighbors=None):
    self.val = val
    self.neighbors = neighbors if neighbors is not None else []


class Solution:
  def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
    if not node:
      return node

    created: Dict[int, Node] = dict()
    q: Deque[Node] = deque()

    q.append(node)
    ans = Node(node.val)
    created[1] = ans

    while len(q) != 0:
      curr = q.popleft()
      for n in curr.neighbors:
        if not n.val in created:
          new_node = Node(n.val)
          created[new_node.val] = new_node
          q.append(n)
        created[curr.val].neighbors.append(created[n.val])

    return ans
