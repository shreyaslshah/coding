#
# @lc app=leetcode id=621 lang=python3
#
# [621] Task Scheduler
# https://leetcode.com/problems/task-scheduler/description/

# @lc code=start
from typing import List
import queue
from collections import deque, defaultdict


class Solution:
  def leastInterval(self, tasks: List[str], n: int) -> int:
    currtime = 0
    q = deque()
    heap = queue.PriorityQueue()

    d = defaultdict(int)
    for task in tasks:
      d[task] += 1
    for k, v in d.items():
      heap.put(-v)
    
    ans = 0
    
    while heap.qsize()>0 or q:
      if q:
        (count, time) = q.popleft()
        if time<=currtime:
          heap.put(-count)
        else:
          q.appendleft((count, time))
      if heap.qsize():
        count = -heap.get()
        count -=1
        ans+=1
        currtime+=1
        if count:
          q.append((count, currtime+n))
      else:
        ans+=1
        currtime+=1

    return ans





      # @lc code=end
s = Solution()
print(s.leastInterval(tasks = ["A","A","A","B","B","B"], n = 2))
# print(s.leastInterval(["A", "A", "A", "A", "A",
      # "A", "B", "C", "D", "E", "F", "G"], n=1))
