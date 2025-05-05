# https://leetcode.com/problems/spiral-matrix/

from typing import List


class Solution:
  def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
    rows = len(matrix)
    cols = len(matrix[0])
    n = rows*cols

    ans = []
    i = 0
    j = -1

    while rows != 0 and cols != 0:
      for _ in range(cols):
        j += 1
        ans.append(matrix[i][j])
        n -= 1
      rows -= 1

      if not n:
        break

      for _ in range(rows):
        i += 1
        ans.append(matrix[i][j])
        n -= 1
      cols -= 1

      if not n:
        break

      for _ in range(cols):
        j -= 1
        ans.append(matrix[i][j])
        n -= 1
      rows -= 1

      if not n:
        break

      for _ in range(rows):
        i -= 1
        ans.append(matrix[i][j])
        n -= 1
      cols -= 1

    return ans


s = Solution()
print(s.spiralOrder([[1, 2, 3, 4]]))


class Solution:
  def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
    res = []
    if len(matrix) == 0:
      return res
    row_begin = 0
    col_begin = 0
    row_end = len(matrix)-1
    col_end = len(matrix[0])-1
    while (row_begin <= row_end and col_begin <= col_end):
      for i in range(col_begin, col_end+1):
        res.append(matrix[row_begin][i])
      row_begin += 1
      for i in range(row_begin, row_end+1):
        res.append(matrix[i][col_end])
      col_end -= 1
      if (row_begin <= row_end):
        for i in range(col_end, col_begin-1, -1):
          res.append(matrix[row_end][i])
        row_end -= 1
      if (col_begin <= col_end):
        for i in range(row_end, row_begin-1, -1):
          res.append(matrix[i][col_begin])
        col_begin += 1
    return res
