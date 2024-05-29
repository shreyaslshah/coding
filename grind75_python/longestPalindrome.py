# https://leetcode.com/problems/longest-palindrome/description/

class Solution:
  def longestPalindrome(self, s: str) -> int:
    d = {}
    ans = 0

    for char in s:
      if not char in d:
        d[char] = 1
      else:
        d[char]+=1
    
    single = False

    for char, freq in d.items():
      if freq%2==0:
        ans +=freq
      else:
        single=True
        ans += freq-1
    
    if single:
      ans+=1
      
    return ans

s = Solution()
print(s.longestPalindrome("abccccdd"))

        
"""

Approach for this Problem:

Initialize two variables, oddCount to store the number of characters with an odd count of occurrences and an unordered map ump to store the count of each character in the string.

Iterate through the string and for each character ch, increment the count of that character in the unordered map.

If the count of the current character ch is odd, increment oddCount. If the count is even, decrement oddCount.

If oddCount is greater than 1, return s.length() - oddCount + 1, which is the maximum length of a palindrome that can be formed by using all but one character with an odd count of occurrences.

If oddCount is not greater than 1, return s.length(), which is the length of the original string, as all characters can be used to form a palindrome.

"""

"""

class Solution:
    def longestPalindrome(self, s: str) -> int:
        odd_count = 0
        d = {}
        for ch in s:
            if ch in d:
                d[ch] += 1
            else:
                d[ch] = 1
            if d[ch] % 2 == 1:
                odd_count += 1
            else:
                odd_count -= 1
        if odd_count > 1:
            return len(s) - odd_count + 1
        return len(s)

"""
