# https://leetcode.com/problems/find-all-anagrams-in-a-string/

from typing import List

# class Solution:
#   def findAnagrams(self, s: str, p: str) -> List[int]:
#     l = 0
#     r = len(p)-1
#     dic = dict()
#     for char in p:
#       if char in dic:
#         dic[char] += 1
#       else:
#         dic[char] = 1
#     zeroes = 0
#     for i in range(len(p)):
#       if i < len(s) and s[i] in dic:
#         dic[s[i]] -= 1
#         if dic[s[i]] == -1:
#           zeroes -= 1
#         elif dic[s[i]] == 0:
#           zeroes += 1
#     ans = []
#     while r < len(s):
#       if zeroes == len(dic):
#         ans.append(l)
#       if s[l] in dic:
#         dic[s[l]] += 1
#         if dic[s[l]] == 1:
#           zeroes -= 1
#         elif dic[s[l]] == 0:
#           zeroes += 1
#       l += 1
#       if r+1 < len(s) and s[r+1] in dic:
#         dic[s[r+1]] -= 1
#         if dic[s[r+1]] == -1:
#           zeroes -= 1
#         elif dic[s[r+1]] == 0:
#           zeroes += 1
#       r += 1
#     return ans
  

class Solution:
  def findAnagrams(self, s: str, p: str) -> List[int]:
    l = 0
    r = len(p)-1
    dic = dict()

    for char in p:
      if char in dic:
        dic[char] += 1
      else:
        dic[char] = 1

    for i in range(len(p)):
      if i < len(s) and s[i] in dic:
        dic[s[i]] -= 1

    ans = []

    if all(value == 0 for value in dic.values()):
      ans.append(l)
    
    while r < len(s):
      if s[l] in dic:
        dic[s[l]] += 1
      l += 1

      if r+1 < len(s) and s[r+1] in dic:
        dic[s[r+1]] -= 1
      r += 1
      if all(value == 0 for value in dic.values()):
        ans.append(l)

    return ans

s = Solution()
print(s.findAnagrams(s="abacbabc", p="abc"))


