# https://leetcode.com/problems/rotting-oranges/

from collections import deque
from typing import List


class Solution:
  def valid(self, r, c, grid):
    if 0 <= r < len(grid) and 0 <= c < len(grid[0]):
      return True
    return False

  def orangesRotting(self, grid: List[List[int]]) -> int:
    directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]
    mins = 0
    q = deque()
    fresh = 0

    # add all rotten oranges to the q
    for i in range(len(grid)):
      for j in range(len(grid[0])):
        if grid[i][j] == 2:
          q.append((i, j))
        elif grid[i][j] == 1:
          fresh += 1

    while q and fresh > 0:
      mins += 1
      for _ in range(len(q)):
        (i, j) = q.popleft()
        for d in directions:
          new_i = i+d[0]
          new_j = j+d[1]
          if self.valid(new_i, new_j, grid) and grid[new_i][new_j] == 1:
            grid[new_i][new_j] = 2
            fresh -= 1
            q.append((new_i, new_j))

    return mins if fresh<=0 else -1
