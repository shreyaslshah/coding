#
# @lc app=leetcode id=1334 lang=python3
#
# [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
# https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
# floyd warshall algorithm

# @lc code=start
from typing import List
import sys


class Solution:
  def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
    mat = [[sys.maxsize for _ in range(n)] for _ in range(n)]

    for i in range(n):
      mat[i][i] = 0

    for edge in edges:
      mat[edge[0]][edge[1]] = edge[2]
      mat[edge[1]][edge[0]] = edge[2]

    for k in range(n):
      for i in range(n):
        for j in range(n):
          mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j])

    cnt = [0] * n
    for i in range(n):
      for j in range(n):
        if i == j:
          continue
        if mat[i][j] <= distanceThreshold:
          cnt[j] += 1

    ans = 0
    for i in range(n):
      if cnt[i] <= cnt[ans]:
        ans = i
    return ans
  
    # @lc code=end


s = Solution()
print(s.findTheCity(4,
                    [[0, 1, 3], [1, 2, 1], [1, 3, 4], [2, 3, 1]],
                    4))
