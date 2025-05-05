#
# @lc app=leetcode id=224 lang=python3
#
# [224] Basic Calculator
# https://leetcode.com/problems/basic-calculator/description/

# @lc code=start
class Solution:
  def calculate(self, s: str) -> int:
    stack = []
    sign = 1
    ans = 0
    i = 0

    while i < len(s):

      if s[i].isdigit():
        currNum = 0
        while i < len(s) and s[i].isdigit():
          currNum = currNum*10 + int(s[i])
          i += 1
        ans += sign*currNum
        continue

      elif s[i] == '+':
        sign = 1

      elif s[i] == '-':
        sign = -1

      elif s[i] == '(':
        stack.append(ans)
        stack.append(sign)
        ans = 0
        sign = 1

      elif s[i] == ')':
        ans = stack.pop()*ans
        ans += stack.pop()

      i += 1

    return ans

    # @lc code=end
s = Solution()
print(s.calculate("2147483647"))
