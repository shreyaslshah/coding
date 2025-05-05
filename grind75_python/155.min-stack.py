#
# @lc app=leetcode id=155 lang=python3
#
# [155] Min Stack
# https://leetcode.com/problems/min-stack/description/

# @lc code=start

import sys


class MinStack:

  def __init__(self):
    self.stack = []
    self.minYet = sys.maxsize

  def push(self, val: int) -> None:
    if val < self.minYet:
      self.stack.append((val, val))
      self.minYet = val
    else:
      self.stack.append((val, self.minYet))

  def pop(self) -> None:
    self.stack.pop()
    if not self.stack:
      self.minYet = sys.maxsize
    else:
      self.minYet = self.stack[-1][1]

  def top(self) -> int:
    return self.stack[-1][0]

  def getMin(self) -> int:
    return self.stack[-1][1]

    # Your MinStack object will be instantiated and called as such:
    # obj = MinStack()
    # obj.push(val)
    # obj.pop()
    # param_3 = obj.top()
    # param_4 = obj.getMin()
    # @lc code=end

