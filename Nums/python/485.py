from typing import List


class Solution:
    def findMaxConsecutiveOnes(self, nums:List[int]) -> int:
        maxcount = count =0
        for i, num in enumerate(nums):
            if num == 1:
                count += 1
            else:
                maxcount = max(maxcount, count)
                count = 0
        maxcount = max(maxcount, count)
        return maxcount

def main():
    s = Solution()
    l = [0, 1, 1, 0]
    print(f"maxcount is {s.findMaxConsecutiveOnes(l)}")

if __name__ == '__main__':
    main()

