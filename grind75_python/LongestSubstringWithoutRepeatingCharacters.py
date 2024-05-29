# https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution:
  def lengthOfLongestSubstring(self, s: str) -> int:
    st = set()
    ans = 0
    l = r = 0

    while r<len(s):
      if s[r] in st:
        while s[l]!=s[r]:
          st.discard(s[l])
          l+=1
        l+=1
        r+=1
      else:
        ans = max(ans, r-l+1)
        st.add(s[r])
        r+=1
    return ans


s = Solution()
print(s.lengthOfLongestSubstring("tmmzuxt"))




"""""

indext    0    1    2    3   4   5   6   7
string    a    c    b    d   b   a   c   d
          ^                  ^
          |                  |
		left               right
		seen = {a : 0, c : 1, b : 2, d: 3} 
		# case 1: seen[b] = 2, current window  is s[0:4] , 
		#        b is inside current window, seen[b] = 2 > left = 0. Move left pointer to seen[b] + 1 = 3
		seen = {a : 0, c : 1, b : 4, d: 3} 
indext    0    1    2    3   4   5   6   7
string    a    c    b    d   b   a   c   d
						 ^   ^
					     |   |
				      left  right		
indext    0    1    2    3   4   5   6   7
string    a    c    b    d   b   a   c   d
					     ^       ^
					     |       |
				       left    right		
		# case 2: seen[a] = 0,which means a not in current window s[3:5] , since seen[a] = 0 < left = 3 
		# we can keep moving right pointer.
        
"""


"""
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        l = 0
        output = 0
        for r in range(len(s)):
            
            # If s[r] not in seen, we can keep increasing the window size by moving right pointer
            
            if s[r] not in seen:
                output = max(output,r-l+1)
            
            # There are two cases if s[r] in seen:
            # case1: s[r] is inside the current window, we need to change the window by moving left pointer to seen[s[r]] + 1.
            # case2: s[r] is not inside the current window, we can keep increase the window
            
            else:
                if seen[s[r]] < l:
                    output = max(output,r-l+1)
                else:
                    l = seen[s[r]] + 1
            seen[s[r]] = r
        return output
"""