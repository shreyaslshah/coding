# https://leetcode.com/problems/number-of-islands/

from typing import List
from collections import deque


class Solution:
  def valid(self, r, c, grid):
    if 0 <= r < len(grid) and 0 <= c < len(grid[0]):
      return True
    return False

  def numIslands(self, grid: List[List[str]]) -> int:
    visited = set()
    directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]

    ans = 0

    for i in range(len(grid)):
      for j in range(len(grid[0])):
        if grid[i][j] == "1" and not (i, j) in visited:
          ans += 1
          q = deque()
          q.append((i, j))
          visited.add((i, j))
          while len(q) != 0:
            (r, c) = q.popleft()
            for d in directions:
              new_r = r+d[0]
              new_c = c+d[1]
              if self.valid(new_r, new_c, grid) and grid[new_r][new_c] == "1" and not (new_r, new_c) in visited:
                q.append((new_r, new_c))
                visited.add((new_r, new_c))

    return ans


s = Solution()
print(s.numIslands([["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"], [
      "1", "1", "0", "0", "0"], ["0", "0", "0", "0", "0"]]))
