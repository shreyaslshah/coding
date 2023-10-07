# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

import sys


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        globalMax = 0
        localMax = 0
        for i in range(1, len(prices)):
            localMax = max(
                prices[i] - prices[i - 1], localMax + prices[i] - prices[i - 1]
            )
            globalMax = max(globalMax, localMax)

        return globalMax if globalMax > 0 else 0


# Declare a buy variable to store the buy cost and max_profit to store the maximum profit.
# Initialize the buy variable to the first element of the prices array.
# Iterate over the prices array and check if the current price is minimum or not.
# If the current price is minimum then buy on this ith day.
# If the current price is greater than the previous buy then make profit from it and maximize the max_profit.
# Finally, return the max_profit.


# Python program for the above approach:


def maxProfit(prices, n):
    buy = prices[0]
    max_profit = 0
    for i in range(1, n):
        # Checking for lower buy value
        if buy > prices[i]:
            buy = prices[i]

        # Checking for higher profit
        elif prices[i] - buy > max_profit:
            max_profit = prices[i] - buy
    return max_profit
