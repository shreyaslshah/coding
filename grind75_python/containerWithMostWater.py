# https://leetcode.com/problems/container-with-most-water/description/

# We start with two pointers, one at the beginning of the list and one at the end. These pointers represent the two lines that make the container as wide as possible.

# In each round of the loop, we calculate the area of the container formed by the lines pointed to by our pointers. To do that, we take the shorter of the two lines (that's h) and multiply it by the distance between the lines (that's w).

# If the current area is larger than the maximum area we've seen so far, we update our record of the maximum area.

# Next, we have to decide which pointer to move. We move the pointer that points to the shorter line, because that's the only way to potentially increase the area (by making the container wider) without reducing the height.

# We keep doing this until the pointers meet or cross. At that point, we've considered all possible container areas, and our max_area will hold the answer we're looking for.

# The magic here is in always choosing the pointer that points to the shorter line. That way, we explore all possible containers efficiently, and we end up with the maximum area.

class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxArea = 0
        left = 0
        right = len(height) -1
        while left < right:
            h = min(height[left], height[right])
            w = right-left
            maxArea = max(maxArea, (h*w))
            if height[left] < height[right]:
                left +=1
            else:
                right -=1
        return maxArea
        

    


