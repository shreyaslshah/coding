# https://leetcode.com/problems/01-matrix/

from typing import List
from queue import Queue
import sys


class Solution:
  def valid(self, i, j, mat):
    if 0 <= i < len(mat) and 0 <= j < len(mat[0]):
      return True
    return False

  def updateMatrixBFS(self, mat: List[List[int]]) -> List[List[int]]:

    ans = [[0 for _ in range(len(mat[0]))] for _ in range(len(mat))]

    directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]

    q = Queue()
    visited = set()

    # add all the 0s to the q. we will do bfs from all the 0s and as soon as we encounter a 1 we will put the distance
    for i in range(len(mat)):
      for j in range(len(mat[0])):
        if mat[i][j] == 0:
          q.put((i, j))
          visited.add((i, j))

    dist = 0

    while not q.empty():

      # for each level away from a 0 we increment the distance
      for _ in range(q.qsize()):

        i, j = q.get()

        if mat[i][j] == 1:
          ans[i][j] = dist

        for d in directions:
          new_i = i+d[0]
          new_j = j+d[1]

          # we will add all the surrounding 1s. surrounding 0s will not be added because they are already in the visited set.
          if self.valid(new_i, new_j, mat) and (new_i, new_j) not in visited:
            q.put((new_i, new_j))
            visited.add((new_i, new_j))

      dist += 1

    return ans

  def updateMatrixDP(self, mat: List[List[int]]) -> List[List[int]]:

    ans = [[sys.maxsize for _ in range(len(mat[0]))] for _ in range(len(mat))]

    for i in range(len(mat)):
      for j in range(len(mat[0])):
        if mat[i][j] == 0:
          ans[i][j] = 0
        else:
          up = ans[i-1][j] if self.valid(i-1, j, mat) else sys.maxsize
          left = ans[i][j-1] if self.valid(i, j-1, mat) else sys.maxsize
          ans[i][j] = 1 + min(up, left)

    for i in range(len(mat) - 1, -1, -1):
      for j in range(len(mat[0]) - 1, -1, -1):
        down = ans[i+1][j] if self.valid(i+1, j, mat) else sys.maxsize
        right = ans[i][j+1] if self.valid(i, j+1, mat) else sys.maxsize
        ans[i][j] = min(ans[i][j], 1 + min(down, right))

    return ans


s = Solution()
# print(s.updateMatrix([[1, 1, 1], [1, 1, 1], [1, 1, 0]]))
