#
# @lc app=leetcode id=787 lang=python3
#
# [787] Cheapest Flights Within K Stops
# https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
# bellman ford algorithm

# @lc code=start
from typing import List


class Solution:
  def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
    prices = [float("inf")] * n
    prices[src] = 0

    for i in range(K+1):
      tmp_prices = prices.copy()
      for s, d, p in flights: # src, dst, price
        if prices[s] == float("inf"):
          continue
        if tmp_prices[d] > prices[s] + p:
          tmp_prices[d] = prices[s] + p
      prices = tmp_prices

    return -1 if prices[dst] == float("inf") else prices[dst]

  # @lc code=end
