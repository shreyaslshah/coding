# https://leetcode.com/problems/maximum-profit-in-job-scheduling/

from typing import List
import bisect


class Solution:
  # this gives MLE
  def jobSchedulingMLE(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
    data = sorted(zip(endTime, startTime, profit))
    n = max(endTime)
    dp = [0]*(n+1)
    curr = 0
    i = 1
    while i < n+1:
      if i < data[curr][0]:
        dp[i] = dp[i-1]
      elif i == data[curr][0]:
        dp[i] = max(dp[i-1], data[curr][2]+dp[data[curr][1]], dp[i])
        curr += 1
        if curr < len(data) and data[curr-1][0] == data[curr][0]:
          continue
      i += 1

    return dp[n]

  def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
    jobs = sorted(zip(endTime, startTime, profit))
    endTime = [j[0] for j in jobs]
    n = len(jobs)
    dp = [0]*(n+1)

    for i in range(1, n+1):
      # i-1 because we are starting from 1
      e = jobs[i-1][0]
      s = jobs[i-1][1]
      p = jobs[i-1][2]

      # don't pick current job
      dp[i] = dp[i-1]

      # pick current job
      idx = bisect.bisect_right(endTime, s) - 1
      # bisect_right will return the index of the end time just greater than s. we do -1 to get the final occurence of the end time less than or equal to s.
      # we do +1 because we are starting from 1 in dp array.
      # if bisect right returned 0 and idx became -1 we want the 0th index of the dp array
      dp[i] = max(dp[i], p+(dp[idx+1] if idx != -1 else 0))

    return dp[-1]


s = Solution()
print(s.jobScheduling(startTime=[1, 2, 3, 3], endTime=[
      3, 4, 5, 1000000000], profit=[50, 10, 40, 70]))
