# https://leetcode.com/problems/product-of-array-except-self/

from typing import List

class Solution:
  def productExceptSelf(self, nums: List[int]) -> List[int]:
    leftProd = [1]
    rightProd = [1]

    for num in nums:
      leftProd.append(leftProd[-1]*num)
    for i in reversed(range(len(nums))):
      rightProd.append(rightProd[-1]*nums[i])

    ans = []

    for i in range(1, len(nums)+1):
      ans.append(leftProd[i-1]*rightProd[len(nums)-i])
    
    return ans

s = Solution()
print(s.productExceptSelf([-1,1,0,-3,3]))



# Create an array product and initialize its value to 1 and a variable temp = 1.

# Traverse the array from start to end.

# For every index i update product[i] as product[i] = temp and temp = temp * array[i], i.e store the product upto i-1 index from the start of array.

# initialize temp = 1 and traverse the array from last index to start.

# For every index i update product[i] as product[i] = product[i] * temp and temp = temp * array[i], i.e multiply with the product upto i+1 index from the end of array.

# Print the product array.


# Python3 program for A Product Array Puzzle 
# def productArray(arr, n): 

# 	# Base case 
# 	if n == 1: 
# 		print(0) 
# 		return

# 	i, temp = 1, 1

# 	# Allocate memory for the product array 
# 	prod = [1 for i in range(n)] 

# 	# Initialize the product array as 1 

# 	# In this loop, temp variable contains product of 
# 	# elements on left side excluding arr[i] 
# 	for i in range(n): 
# 		prod[i] = temp 
# 		temp *= arr[i] 

# 	# Initialize temp to 1 for product on right side 
# 	temp = 1

# 	# In this loop, temp variable contains product of 
# 	# elements on right side excluding arr[i] 
# 	for i in range(n - 1, -1, -1): 
# 		prod[i] *= temp 
# 		temp *= arr[i] 

# 	# Print the constructed prod array 
# 	for i in range(n): 
# 		print(prod[i], end=" ") 

# 	return


# # Driver Code 
# arr = [10, 3, 5, 6, 2] 
# n = len(arr) 
# print("The product array is: n") 
# productArray(arr, n) 

