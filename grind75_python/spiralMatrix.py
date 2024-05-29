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
        j+=1
        ans.append(matrix[i][j])
        n-=1
      rows-=1

      if not n:
        break

      for _ in range(rows):
        i+=1
        ans.append(matrix[i][j])
        n-=1
      cols-=1

      if not n: 
        break

      for _ in range(cols):
        j-=1
        ans.append(matrix[i][j])
        n-=1
      rows-=1

      if not n:
        break

      for _ in range(rows):
        i-=1
        ans.append(matrix[i][j])
        n-=1
      cols-=1
    
    return ans
  
s = Solution()
print(s.spiralOrder([[1,2,3,4]]))





