# https://leetcode.com/problems/time-based-key-value-store/

class TimeMap:

  def __init__(self):
    self.dic = dict()

  def set(self, key: str, value: str, timestamp: int) -> None:
    if key in self.dic:
      self.dic[key].append((timestamp, value))
    else:
      self.dic[key] = [(timestamp, value)]

  def get(self, key: str, timestamp: int) -> str:
    if key not in self.dic:
      return ""
    ans = ""
    l = 0
    h = len(self.dic[key])-1
    m = 0
    while l <= h:
      m = (l+h)//2
      if timestamp == self.dic[key][m][0]:
        ans = self.dic[key][m][1]
        break
      elif timestamp > self.dic[key][m][0]:
        ans = self.dic[key][m][1]
        l = m+1
      else:
        h = m-1
    return ans


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
