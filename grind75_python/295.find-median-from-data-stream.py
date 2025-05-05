#
# @lc app=leetcode id=295 lang=python3
#
# [295] Find Median from Data Stream
# https://leetcode.com/problems/find-median-from-data-stream/description/


# @lc code=start
import heapq
import queue


class MedianFinder:
  def __init__(self):
    # two heaps, large, small, minheap, maxheap
    # heaps should be equal size
    self.small, self.large = [], []  # maxHeap, minHeap (python default)

  def addNum(self, num: int) -> None:
    if self.large and num > self.large[0]:
      heapq.heappush(self.large, num)
    else:
      heapq.heappush(self.small, -1 * num)

    # uneven sizes
    if len(self.small) > len(self.large) + 1:
      val = -1 * heapq.heappop(self.small)
      heapq.heappush(self.large, val)
    if len(self.large) > len(self.small) + 1:
      val = heapq.heappop(self.large)
      heapq.heappush(self.small, -1 * val)

  def findMedian(self) -> float:
    if len(self.small) > len(self.large):
      return -1 * self.small[0]
    elif len(self.large) > len(self.small):
      return self.large[0]
    return (-1 * self.small[0] + self.large[0]) / 2.0

  # Your MedianFinder object will be instantiated and called as such:
  # obj = MedianFinder()
  # obj.addNum(num)
  # param_2 = obj.findMedian()
  # @lc code=end


s = MedianFinder()
s.addNum(1)
s.addNum(2)
print(s.findMedian())
s.addNum(3)
print(s.findMedian())
