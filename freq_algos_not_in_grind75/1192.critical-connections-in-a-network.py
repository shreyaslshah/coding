#
# @lc app=leetcode id=1192 lang=python3
#
# [1192] Critical Connections in a Network
# https://leetcode.com/problems/critical-connections-in-a-network/description/
# articulation points - tarjan's algorithm

# @lc code=start
from collections import defaultdict
import sys
from typing import List


class Solution:
  def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
    adj = defaultdict(list)

    for conn in connections:
      adj[conn[0]].append(conn[1])
      adj[conn[1]].append(conn[0])

    visited = set()
    low = [sys.maxsize for _ in range(n)]
    timeOfInsertion = [sys.maxsize for _ in range(n)]
    timer = 0
    ans = []

    def dfs(node, parent):
      nonlocal timer
      visited.add(node)
      low[node] = timeOfInsertion[node] = timer
      timer += 1

      for nei in adj[node]:
        if nei == parent:
          continue

        if nei not in visited:
          dfs(nei, node)
          low[node] = min(low[node], low[nei])
          if low[nei] > timeOfInsertion[node]:
            ans.append([nei, node])

        else:
          low[node] = min(low[node], low[nei])

    dfs(0, -1)
    return ans

    # @lc code=end
