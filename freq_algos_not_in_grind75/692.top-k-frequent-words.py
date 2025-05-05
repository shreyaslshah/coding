#
# @lc app=leetcode id=692 lang=python3
#
# [692] Top K Frequent Words
#

# @lc code=start
from typing import List
import heapq
from collections import defaultdict


class Solution:
  def topKFrequent(self, words: List[str], k: int) -> List[str]:
    dict = defaultdict(int)
    ans = []
    for word in words:
      dict[word] += 1
    words = []
    for word in dict.keys():
      words.append((-dict[word], word))
    heapq.heapify(words)
    for i in range(k):
      freq, word = heapq.heappop(words)
      freq = -freq
      ans.append((freq, word))

    ans.sort(key=lambda x: (-x[0], x[1]))
    return [x[1] for x in ans]

    # @lc code=end


s = Solution()
print(s.topKFrequent([]))


# def topKFrequent(self, words: List[str], k: int) -> List[str]:
#   dict = {}
#   for x in words:
#     if x in dict:
#       dict[x] += 1
#     else:
#       dict[x] = 1
#   res = sorted(dict, key=lambda x: (-dict[x], x))
#   return res[:k]
