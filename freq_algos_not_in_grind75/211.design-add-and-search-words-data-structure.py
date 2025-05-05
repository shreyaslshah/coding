#
# @lc app=leetcode id=211 lang=python3
#
# [211] Design Add and Search Words Data Structure
#

# @lc code=start

class Node:
  def __init__(self):
    self.children = {}
    self.wordEnd = False


class WordDictionary:

  def __init__(self):
    self.root = Node()

  def addWord(self, word: str) -> None:
    node = self.root
    for char in word:
      if char not in node.children:
        node.children[char] = Node()
      node = node.children[char]
    node.wordEnd = True

  def search(self, word: str) -> bool:
    node = self.root

    def dfs(node, i):
      nonlocal exists
      if i == len(word) and node.wordEnd == True:
        exists = True
        return
      if i == len(word) and node.wordEnd == False:
        return
      char = word[i]
      if char == '.':
        for child in node.children:
          dfs(node.children[child], i+1)
      elif char in node.children:
        dfs(node.children[char], i+1)

    exists = False
    dfs(node, 0)
    return exists

    # Your WordDictionary object will be instantiated and called as such:
    # obj = WordDictionary()
    # obj.addWord(word)
    # param_2 = obj.search(word)
    # @lc code=end
