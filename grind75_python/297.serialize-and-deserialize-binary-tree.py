#
# @lc app=leetcode id=297 lang=python3
#
# [297] Serialize and Deserialize Binary Tree
# https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

# @lc code=start
# Definition for a binary tree node.
from collections import deque


# class TreeNode(object):
#   def __init__(self, x):
#     self.val = x
#     self.left = None
#     self.right = None


class Codec:

  def serialize(self, root):
    if not root:
      return ''
    q = deque()
    ans = [root.val]
    q.append(root)

    while q:
      node = q.popleft()
      if node:
        q.append(node.left)
        q.append(node.right)
        ans.append(str(node.left.val) if node.left else 'n')
        ans.append(str(node.right.val) if node.right else 'n')

    return (''.join(str(element)+' ' for element in ans))[:-1]

  def deserialize(self, data):
    if not data:
      return None
    data = [x for x in data.split(' ')]
    curr = 0
    q = deque()
    ans = TreeNode(int(data[curr]))
    q.append(ans)
    curr += 1

    while curr < len(data):
      node = q.popleft()
      if data[curr] != 'n':
        left = TreeNode(int(data[curr]))
        node.left = left
        q.append(left)
      curr += 1
      if curr < len(data) and data[curr] != 'n':
        right = TreeNode(int(data[curr]))
        node.right = right
        q.append(right)
      curr += 1

    return ans

    # Your Codec object will be instantiated and called as such:
    # ser = Codec()
    # deser = Codec()
    # ans = deser.deserialize(ser.serialize(root))
    # @lc code=end
