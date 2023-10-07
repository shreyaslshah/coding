# https://leetcode.com/problems/two-sum/description/


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}

        for i in range(len(nums)):
            remainder = target - nums[i]
            if remainder in map:
                return [map[remainder], i]
            else:
                map[nums[i]] = i
