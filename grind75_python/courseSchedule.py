# https://leetcode.com/problems/course-schedule/

from typing import List


class Solution:
  def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

    def dfs(i):
      nonlocal ans
      stack[i] = True
      visited.add(i)
      for nei in adj_list[i]:
        if stack[nei]:
          ans = False
          return
        if not nei in visited:
          dfs(nei)
      stack[i] = False

    # make adjacency list
    adj_list = [[] for _ in range(numCourses)]
    for pair in prerequisites:
      adj_list[pair[0]].append(pair[1])

    # do dfs, check if any loops
    ans = True
    stack = [False for _ in range(numCourses)]
    visited = set()
    for i in range(len(adj_list)):
      if ans == False:
        return ans
      if (not i in visited):
        dfs(i)

    return ans


s = Solution()
print(s.canFinish(numCourses=3, prerequisites=[[0, 1], [0, 2], [1, 2]]))
