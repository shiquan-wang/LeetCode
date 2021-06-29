from typing import List


class Solution:
    def threeSumClosest(self, nums:List[int], target:int)->int:
        nums.sort()
        n = len(nums)
        bestsum = 10**7
            
        for i in range(n):
            if i>0 and nums[i]==nums[i-1]:
                continue
            pb, pc = i+1, n-1
            while(pb<pc):
                sum = nums[i]+nums[pb]+nums[pc]

                if abs(target-sum) < abs(target-bestsum):
                    bestsum = sum
                
                if sum == target:
                    return target
                if sum < target:
                    pb = pb+1
                else:
                    pc = pc-1
        return bestsum

l = [-1, 2, 1, -4]
s = Solution()
print(s.threeSumClosest(l, 1))
