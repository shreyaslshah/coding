# https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

import sys


class Solution:
  # Function to find the minimum number of platforms required at the
  # railway station such that no train waits.
  def minimumPlatform(self, n, arr, dep):
    arr = sorted(arr)
    dep = sorted(dep)

    ans = 1
    curr = 0

    arrIdx = depIdx = 0

    while arrIdx < n and depIdx < n:
      if arrIdx==n-1:
        curr-=1
        depIdx+=1
        ans = max(ans, curr)
        continue
      if arr[arrIdx]<=dep[depIdx]:
        curr+=1
        arrIdx+=1
        ans = max(ans, curr)
      else:
        curr-=1
        depIdx+=1
        ans = max(ans, curr)
    
    return ans

      

      


if __name__ == '__main__':
  test_cases = int(input())
  for cases in range(test_cases):
    n = int(input())
    arrival = list(map(int, input().strip().split()))
    departure = list(map(int, input().strip().split()))
    ob = Solution()
    print(ob.minimumPlatform(n, arrival, departure))
# } Driver Code Ends
