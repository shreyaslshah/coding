#
# @lc app=leetcode id=1584 lang=python3
#
# [1584] Min Cost to Connect All Points
# https://leetcode.com/problems/min-cost-to-connect-all-points/description/
# Kruskal’s Minimum Spanning Tree
# prim's algorithm - used this to solve

# @lc code=start
from collections import defaultdict
from typing import List
import queue


class Solution:
  def minCostConnectPoints(self, points: List[List[int]]) -> int:
    visited = set()
    heap = queue.PriorityQueue()

    adj = defaultdict(list)

    for i in range(len(points)):
      for j in range(i+1, len(points)):
        dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])
        adj[i].append((dist, j))
        adj[j].append((dist, i))
    

    heap.put((0, 0))
    ans = 0

    while heap.qsize()>0 and len(visited)<len(points):
      dist, source = heap.get()
      if source in visited:
        continue
      visited.add(source)
      ans+=dist
      for dist, dest in adj[source]:
        if dest not in visited:
          heap.put((dist, dest))
    
    return ans


      
      
    



    # @lc code=end
