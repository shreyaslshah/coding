# https://leetcode.com/problems/string-to-integer-atoi/

class Solution:
  def myAtoi(self, s: str) -> int:

    ans = 0
    neg = False

    i = 0

    while i < len(s) and s[i] == ' ':
      i+=1
    
    if i < len(s) and s[i] == '-':
      neg = True
      i+=1
    elif i < len(s) and s[i] == '+':
      i+=1
    
    while i < len(s) and 48 <= ord(s[i]) <= 57:
      ans = ans*10 + (ord(s[i])-48)
      i+=1
    
    if neg:
      ans = -ans
    
    if ans < -2**31:
      return -2**31
    if ans > 2**31-1:
      return 2**31-1
    return ans

        