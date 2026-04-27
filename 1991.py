from typing import List

#Use prefix sum advance

class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        leftnum = 0
        for i in range(len(nums)):
            rightnum = total - leftnum - nums[i]
            if leftnum == rightnum:
                return i
            leftnum = leftnum + nums[i]
        return -1