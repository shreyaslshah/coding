#
# @lc app=leetcode id=51 lang=python3
#
# [51] N-Queens
#
from typing import List


# @lc code=start
class Solution:
  def solveNQueens(self, n: int) -> List[List[str]]:
    cols = set()
    positiveDiagonal = set()
    negativeDiagonal = set()

    ans = []
    board = ['.'*n for _ in range(n)]

    def solve(row):
      if row == n:
        ans.append(board.copy())
        return

      for col in range(n):
        if col in cols or row+col in positiveDiagonal or row-col in negativeDiagonal:
          continue
        else:
          board[row] = board[row][:col]+'Q'+board[row][col+1:]
          cols.add(col)
          positiveDiagonal.add(row+col)
          negativeDiagonal.add(row-col)

          solve(row+1)

          board[row] = board[row][:col]+'.'+board[row][col+1:]
          cols.remove(col)
          positiveDiagonal.remove(row+col)
          negativeDiagonal.remove(row-col)

    solve(0)

    return ans


# @lc code=end
