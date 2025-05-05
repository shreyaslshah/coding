#
# @lc app=leetcode id=743 lang=python3
#
# [743] Network Delay Time
# https://leetcode.com/problems/network-delay-time/description/
# dijkstra's algoritm

# @lc code=start
from typing import List
from collections import defaultdict
import queue
import sys


class Solution:
  def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
    adj = defaultdict(list)

    for edge in times:
      adj[edge[0]].append((edge[1], edge[2]))

    heap = queue.PriorityQueue()
    heap.put((0, k))

    visited = set()

    ans = [sys.maxsize]*(n+1)
    ans[k] = 0
    ans[0] = 0

    while heap.qsize()>0:
      dist, source = heap.get()
      if source in visited:
        continue
      else:
        visited.add(source)

      for ele in adj[source]:
        dest = ele[0]
        weight = ele[1]
        if ans[dest] > dist + weight:
          ans[dest] = dist + weight
          heap.put((ans[dest], dest))

    ans = max(ans)

    return -1 if ans >= sys.maxsize else ans

    # @lc code=end


s = Solution()
print(s.networkDelayTime(times=[[2, 1, 1], [2, 3, 1], [3, 4, 1]], n=4, k=2))
