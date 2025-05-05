#
# @lc app=leetcode id=146 lang=python3
#
# [146] LRU Cache
# https://leetcode.com/problems/lru-cache/description/

# @lc code=start


# dictionaries in Python are insertion ordered as of Python 3.7



class LRUCache:

    def __init__(self, capacity: int):
        self.dict = {}
        self.capacity = capacity   

    def get(self, key: int) -> int:
        if key not in self.dict:
            return -1
        val = self.dict.pop(key)  #Remove it first before inserting it at the end again
        self.dict[key] = val   
        return val        

    def put(self, key: int, value: int) -> None:
        if key in self.dict:    
            self.dict.pop(key)
        else:
            if len(self.dict) == self.capacity:
                del self.dict[next(iter(self.dict))]         
        self.dict[key] = value

  # Your LRUCache object will be instantiated and called as such:
  # obj = LRUCache(capacity)
  # param_1 = obj.get(key)
  # obj.put(key,value)
  # @lc code=end
