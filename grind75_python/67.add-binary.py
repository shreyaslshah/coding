#
# @lc app=leetcode id=67 lang=python3
#
# [67] Add Binary
# https://leetcode.com/problems/add-binary/description/

# @lc code=start
class Solution:
  def addBinary(self, a: str, b: str) -> str:
    if len(a) < len(b):
      a, b = b, a

    b = (len(a)-len(b))*'0' + b

    carry = 0

    ptr = len(a)-1

    ans = ''

    while ptr >= 0:
      if int(a[ptr])+int(b[ptr])+carry == 0:
        ans += '0'
        carry = 0

      elif int(a[ptr])+int(b[ptr])+carry == 1:
        ans += '1'
        carry = 0

      elif int(a[ptr])+int(b[ptr])+carry == 2:
        ans += '0'
        carry = 1

      elif int(a[ptr])+int(b[ptr])+carry == 3:
        ans += '1'
        carry = 1

      ptr -= 1

    if carry == 1:
      ans += '1'

    return ans[::-1]

    # @lc code=end


s = Solution()
print(s.addBinary('11', '1'))
