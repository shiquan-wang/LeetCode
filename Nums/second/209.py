
from typing import List


class Solution:
    def minsubArrayLen(self, nums: List[int], target: int)->int:
        start, end = 0, 0
        sum = 0
        res = len(nums) + 1
        sublength = -1
        for end in range(len(nums)):
            sum = sum + nums[end]
            while sum >= target:
                sublength = end - start + 1
                res = min(sublength, res)
                sum -= nums[start]
                start += 1
        return res if res <= len(nums) else 0

s1 = Solution()
print(s1.minsubArrayLen([2, 3, 1, 2, 4, 3], 7))