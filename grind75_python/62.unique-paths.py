#
# @lc app=leetcode id=62 lang=python3
#
# [62] Unique Paths
# https://leetcode.com/problems/unique-paths/description/

# @lc code=start
class Solution:
  def uniquePaths(self, m: int, n: int) -> int:
    grid = [[1 for _ in range(n)] for _ in range(m)]

    for i in range(1,m):
      for j in range(1, n):
        grid[i][j] = grid[i-1][j] + grid[i][j-1]

    return grid[-1][-1]

    # @lc code=end
