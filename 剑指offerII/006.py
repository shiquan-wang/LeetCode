from typing import List

from matplotlib.pyplot import new_figure_manager


class Solution:
    def twoSum2(self, numbers : List[int], target : int) -> List[int]:
        n = len(numbers)
        for i in range(n):
            low, hight = i + 1, n - 1
            while low <- hight:
                mid = (low + hight) // 2
                if numbers[mid] == target - numbers[i]:
                    return [i + 1, mid + 1]
                elif numbers[mid] > target - numbers[i]:
                    hight = mid - 1
                else:
                    low = mid + 1
    
        return [-1, -1]
    
    def twoSum(self, numbers : List[int], target : int) -> List[int]:
        low, high = 0, len(numbers) - 1
        while(low <= high):
            temp = numbers[low] + numbers[high]
            if temp == target:
                return [low, high]
            elif temp < target:
                low += 1
            else:
                high -= 1
        return[-1, -1]