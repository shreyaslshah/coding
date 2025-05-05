#
# @lc app=leetcode id=322 lang=python3
#
# [322] Coin Change
# https://leetcode.com/problems/coin-change/description/

# @lc code=start
from typing import List
import sys


class Solution:
  def coinChange(self, coins: List[int], amount: int) -> int:
    if amount==0:
      return 0
    
    dp = [sys.maxsize for _ in range(amount+1)]
    dp[0] = -1

    coins.sort()

    for i in range(1, amount+1):
      for coin in coins:
        if coin == i:
          dp[i] = 1
          break
        if coin > i:
          break
        remainder = i-coin
        if dp[remainder] != -1:
          dp[i] = min(dp[i], dp[remainder]+1)
      if dp[i] == sys.maxsize:
        dp[i] = -1

    return dp[amount]

    # @lc code=end
