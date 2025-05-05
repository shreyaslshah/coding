#
# @lc app=leetcode id=204 lang=python3
#
# [204] Count Primes
# https://leetcode.com/problems/count-primes/description/

# @lc code=start
class Solution:
  def countPrimes(self, n: int) -> int:
    if n <=2:
      return 0
    
    sieve = [1]*n
    sieve[0] = sieve[1] = 0

    for i in range(2, n):
      if sieve[i]==0:
        continue

      j = 2
      while True:
        if i*j<n:
          sieve[i*j] = 0
          j+=1
        else:
          break
    
    return sum(sieve)

    

    # @lc code=end
