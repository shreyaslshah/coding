# https://leetcode.com/problems/word-search/description/

from typing import List
from collections import deque


class Solution:
  def valid(self, r, c, grid):
    if 0 <= r < len(grid) and 0 <= c < len(grid[0]):
      return True
    return False

  def exist(self, board: List[List[str]], word: str) -> bool:

    def dfs(i, j, currIdx):
      nonlocal found
      if wordLen-1 == currIdx:
        found = True
        return
      stack.add((i, j))
      for d in directions:
        new_i = i+d[0]
        new_j = j+d[1]
        if self.valid(new_i, new_j, board) and not (new_i, new_j) in stack and board[new_i][new_j] == word[currIdx+1]:
          dfs(new_i, new_j, currIdx+1)
      stack.remove((i, j))

    directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]
    wordLen = len(word)
    for i in range(len(board)):
      for j in range(len(board[0])):
        if board[i][j] == word[0]:
          stack = set()
          found = False
          dfs(i, j, 0)
          if found:
            return True
    return False


s = Solution()
print(s.exist(board=[["A", "B", "C", "E"], [
      "S", "F", "C", "S"], ["A", "D", "E", "E"]], word="ABCCED"))
