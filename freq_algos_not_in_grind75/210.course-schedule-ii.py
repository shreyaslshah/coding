#
# @lc app=leetcode id=210 lang=python3
#
# [210] Course Schedule II
# https://leetcode.com/problems/course-schedule-ii/description/
# topological sort algorithm

# @lc code=start
from collections import defaultdict
from typing import List


class Solution:
  def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
    adj = dict()

    for n in range(numCourses):
      adj[n] = []

    for edge in prerequisites:
      adj[edge[1]].append(edge[0])
    
    visited = set()
    ans = []
    stack = [False]*numCourses
    cycle = False

    def dfs(i):
      nonlocal cycle
      visited.add(i)
      stack[i] = True
      for j in adj[i]:
        if stack[j]:
          cycle = True
        if j not in visited:
          dfs(j)
      ans.append(i)
      stack[i] = False
    
    for i in adj:
      if i not in visited:
        dfs(i)

    return ans[::-1] if not cycle else []
    # @lc code=end


s = Solution()
print(s.findOrder(2, [[1,0]]))