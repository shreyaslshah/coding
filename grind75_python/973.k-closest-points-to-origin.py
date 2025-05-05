#
# @lc app=leetcode id=973 lang=python3
#
# [973] K Closest Points to Origin
# https://leetcode.com/problems/k-closest-points-to-origin/

# @lc code=start
import math
import queue
from typing import List


class Solution:
  def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
    pq = queue.PriorityQueue()
    for point in points:
      dist = point[0]**2 + point[1]**2
      pq.put((dist, point))
    
    ans = []
    for _ in range(k):
      ans.append(pq.get()[1])
    return ans


# @lc code=end

s = Solution()
print(s.kClosest([[1,3],[-2,2]]
,1))