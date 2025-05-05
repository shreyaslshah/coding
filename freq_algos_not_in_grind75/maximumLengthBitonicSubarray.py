# https://www.geeksforgeeks.org/problems/maximum-length-bitonic-subarray5730/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

# User function Template for python3
class Solution:

  def bitonic(self, arr, n):
    ans = 1
    i = 1

    while i<n:
      increasing = 1
      while i<n and arr[i]>=arr[i-1]:
        increasing+=1
        i+=1
      decreasing = 0
      while i<n and arr[i]<=arr[i-1]:
        decreasing+=1
        i+=1
      ans = max(ans, increasing+decreasing)
      while i>1 and i<n and arr[i-1]==arr[i-2]:
        i-=1

    return ans
  

s = Solution()
print(s.bitonic([25, 43, 83, 59, 59,59, 94, 63, 61, 2, 25, 39, 71, 15], 14))



# if __name__ == '__main__':
#   tc = int(input())
#   while tc > 0:
#     n = int(input())
#     arr = list(map(int, input().strip().split()))
#     ob = Solution()
#     ans = ob.bitonic(arr, n)
#     print(ans)
#     tc -= 1
