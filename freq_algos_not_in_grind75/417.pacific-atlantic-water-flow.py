#
# @lc app=leetcode id=417 lang=python3
#
# [417] Pacific Atlantic Water Flow
#

# @lc code=start
from typing import List


class Solution:
  directions = [[1, 0], [-1, 0], [0, 1],
                [0, -1]]

  def isValid(self, coordinates, heights):
    return True if (0 <= coordinates[0] < len(heights) and 0 <= coordinates[1] < len(heights[0])) else False

  def dfs(self, coordinates, visited, heights):
    if coordinates in visited:
      return

    visited.add(coordinates)

    for d in self.directions:
      i = coordinates[0]+d[0]
      j = coordinates[1]+d[1]

      if self.isValid((i, j), heights) and heights[i][j] >= heights[coordinates[0]][coordinates[1]]:
        self.dfs((i, j), visited, heights)

  def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
    pacific_visited = set()
    atlantic_visited = set()

    for i in range(len(heights[0])):
      self.dfs((0, i), pacific_visited, heights)
      self.dfs((len(heights)-1, i), atlantic_visited, heights)

    for i in range(len(heights)):
      self.dfs((i, 0), pacific_visited, heights)
      self.dfs((i, len(heights[0])-1), atlantic_visited, heights)

    return [list(coord) for coord in pacific_visited & atlantic_visited]

    # @lc code=end
