#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
# https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

# @lc code=start
from typing import List


class Solution:
  def evalRPN(self, tokens: List[str]) -> int:
    stack = []
    for token in tokens:
      if token == '+':
        op2 = stack.pop()
        op1 = stack.pop()
        stack.append(op1+op2)
      elif token == '-':
        op2 = stack.pop()
        op1 = stack.pop()
        stack.append(op1-op2)
      elif token == '*':
        op2 = stack.pop()
        op1 = stack.pop()
        stack.append(op1*op2)
      elif token == '/':
        op2 = stack.pop()
        op1 = stack.pop()
        stack.append(int(op1/op2))
      else:
        stack.append(int(token))
    return stack.pop()
      


    # @lc code=end
