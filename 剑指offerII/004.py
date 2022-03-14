
import collections
from typing import List
from collections import Counter


class Solution:
    def singleNumber(self, nums : List[int]) -> int:
        freq = collections.Counter(nums)
        ans = [num for num, occ in freq.items() if occ == 1][0]
        return ans
s1 = Solution()
print(s1.singleNumber([1, 1, 1, 2]))