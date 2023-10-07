# https://leetcode.com/problems/insert-interval/

from typing import List


class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        if len(intervals) == 0:
            return [newInterval]

        inserted = False

        for i in range(len(intervals)):
            if inserted == False and newInterval[0] < intervals[i][0]:
                intervals.insert(i, newInterval)
                inserted = True

        if inserted == False:
            intervals.append(newInterval)

        ans = [intervals[0]]

        for i in range(1, len(intervals)):
            if intervals[i][0] <= ans[-1][-1]:
                ans[-1][-1] = max(ans[-1][-1], intervals[i][1])
            else:
                ans.append(intervals[i])
        
        return ans


s = Solution()
print(s.insert([[1,2],[3,5],[6,7],[8,10],[12,16]], [4,8]))