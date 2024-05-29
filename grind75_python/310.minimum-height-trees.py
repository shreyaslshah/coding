#
# @lc app=leetcode id=310 lang=python3
#
# [310] Minimum Height Trees
# https://leetcode.com/problems/minimum-height-trees/

# @lc code=start
from collections import defaultdict, deque
from typing import List


class Solution:
  def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
    if n==1:
      return [0]
    adjList = defaultdict(set)
    q = deque()
    for edge in edges:
      adjList[edge[0]].add(edge[1])
      adjList[edge[1]].add(edge[0])
    
    for node in adjList.keys():
      if len(adjList[node])==1:
        q.append(node)
    
    while len(adjList)>2:
      for _ in range(len(q)):
        node = q.popleft()
        nei = adjList[node].pop()
        adjList.pop(node)
        adjList[nei].remove(node)
        if len(adjList[nei])==1:
          q.append(nei)
       
    
    return list(adjList.keys())







    # @lc code=end
