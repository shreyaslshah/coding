# https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article


class Solution:

  # Function to return max value that can be put in knapsack of capacity W.
  def knapSack(self, w, wt, val, n):
    dp = [[0 for _ in range(w+1)] for _ in range(n+1)]

    for i in range(1, n+1):
      for j in range(1, w+1):
        weight = wt[i-1]
        value = val[i-1]
        if weight>j:
          dp[i][j] = dp[i-1][j]
        else:
          select = dp[i-1][j-weight] + value
          notSelect = dp[i-1][j]
          dp[i][j] = max(select, notSelect)
    
    return dp[-1][-1]


      # code here


s = Solution()
print(s.knapSack(4,  [4,5,1], [1,2,3], 3))