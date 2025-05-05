#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#

# @lc code=start
class Solution:
  def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    sorted_strings = strs.copy()

    for i in range(len(sorted_strings)):
      sorted_strings[i] = (sorted(sorted_strings[i]), i)
    
    sorted_strings = sorted(sorted_strings)

    ans = []
    curr = [strs[sorted_strings[0][1]]]

    for i in range(1, len(sorted_strings)):
      if sorted_strings[i][0] == sorted_strings[i-1][0]:
        curr.append(strs[sorted_strings[i][1]])
      else:
        ans.append(curr)
        curr = [strs[sorted_strings[i][1]]]
    
    ans.append(curr)
    
    return ans

    # @lc code=end


# class Solution:
#     def groupAnagrams(self, strs):
#         anagram_map = defaultdict(list)
        
#         for word in strs:
#             sorted_word = ''.join(sorted(word))
#             anagram_map[sorted_word].append(word)
        
#         return list(anagram_map.values())