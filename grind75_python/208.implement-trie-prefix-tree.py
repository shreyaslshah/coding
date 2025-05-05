#
# @lc app=leetcode id=208 lang=python3
#
# [208] Implement Trie (Prefix Tree)
# https://leetcode.com/problems/implement-trie-prefix-tree/description/

# @lc code=start
class Trie:

  def __init__(self):
    self.root = {}

  def insert(self, word: str) -> None:
    curr = self.root
    for char in word:
      if char in curr:
        curr = curr[char]
      else:
        curr[char] = {}
        curr = curr[char]
    curr['end'] = True

  def search(self, word: str) -> bool:
    curr = self.root
    for char in word:
      if char in curr:
        curr = curr[char]
      else:
        return False
    return True if 'end' in curr else False

  def startsWith(self, prefix: str) -> bool:
    curr = self.root
    for char in prefix:
      if char in curr:
        curr = curr[char]
      else:
        return False
    return True

    # Your Trie object will be instantiated and called as such:
    # obj = Trie()
    # obj.insert(word)
    # param_2 = obj.search(word)
    # param_3 = obj.startsWith(prefix)
    # @lc code=end
