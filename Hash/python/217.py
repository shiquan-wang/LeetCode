from typing import List


class Solution:
    def containsDuplicate(self, nums : List[int]) -> bool:
        m = len(nums)
        n = len(set(nums))
        return m != n


s = Solution()
nums = [1, 2, 3, 1]
print(f"result:{s.containsDuplicate(nums)}")

