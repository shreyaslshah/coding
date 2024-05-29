# https://leetcode.com/problems/word-ladder/description/

# explanation:
# https://leetcode.com/problems/word-ladder/solutions/1764371/a-very-highly-detailed-explanation/


from typing import List
from collections import deque


class Solution:
  def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
    visited = set()
    wordList = set(wordList)
    q = deque()
    q.append(beginWord)
    visited.add(beginWord)
    changes = 1

    while q:
      for _ in range(len(q)):
        word = q.popleft()
        if word == endWord:
          return changes
        for i in range(len(word)):
          for letter in range(ord('a'), ord('z') + 1):
            changedWord = word[:i]+chr(letter)+word[i+1:]
            if changedWord in wordList and not changedWord in visited:
              q.append(changedWord)
              visited.add(changedWord)
      changes += 1

    return 0


s = Solution()
print(s.ladderLength("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))
