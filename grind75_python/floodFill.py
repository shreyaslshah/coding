# https://leetcode.com/problems/flood-fill/description/

class Solution:

  def valid(self, r, c, image):
    if 0 <= r < len(image) and 0 <= c < len(image[0]):
      return True
    return False

  def dfs(self, r, c, visited, image, color):
    visited.add((r, c))
    prevColor = image[r][c]
    image[r][c] = color
    if (r+1, c) not in visited and self.valid(r+1, c, image) and image[r+1][c] == prevColor:
      self.dfs(r+1, c, visited, image, color)
    if (r-1, c) not in visited and self.valid(r-1, c, image) and image[r-1][c] == prevColor:
      self.dfs(r-1, c, visited, image, color)
    if (r, c-1) not in visited and self.valid(r, c-1, image) and image[r][c-1] == prevColor:
      self.dfs(r, c-1, visited, image, color)
    if (r, c+1) not in visited and self.valid(r, c+1, image) and image[r][c+1] == prevColor:
      self.dfs(r, c+1, visited, image, color)

  def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
    visited = set()
    self.dfs(sr, sc, visited, image, color)
    return image
