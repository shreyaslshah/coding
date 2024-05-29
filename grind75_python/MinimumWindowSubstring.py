# https://leetcode.com/problems/minimum-window-substring/

class Solution:
  def minWindow(self, s: str, t: str) -> str:
    ans = [-1,-1]
    remaining = len(t)
    l = 0
    r = 0
    dic = {}
    for char in t:
      if char in dic:
        dic[char] += 1
      else:
        dic[char] = 1

    while r<len(s):
      curr = s[r]
      if curr in dic:
        dic[curr]-=1
        if dic[curr]>=0:
          remaining-=1
        while remaining==0:
          if s[l] in dic:
            if ans[0]==ans[1]==-1 or ans[1]-ans[0]>r-l:
              ans = [l, r]
            dic[s[l]]+=1
            if dic[s[l]]>0:
              remaining+=1
          l+=1
      r+=1
    
    return "" if ans[0]==ans[1]==-1 else s[ans[0]:ans[1]+1]
  
s = Solution()
print(s.minWindow(s = "a", t = "a"))


        