from typing import List


class Solution:
    def combinationSum2(self, candiates : List[int], target : int) -> List[List[int]]:
        res = []
        path = []
        def backtracking(candiates, target, sum, start_index):
            if sum == target: 
                res.append(path[:])#当list类型的对象进行append操作时，实际上追加的是该对象的引用。
                #res.append(path) 浅拷贝，res.append(path[:])深拷贝
                return
            for i in range(start_index, len(candiates)):
                if sum + candiates[i] > target: return#剪枝

                if i > start_index and candiates[i] == candiates[i-1]:#直接用startIndex来去重,要对同一树层使用过的元素进行跳过
                    continue

                sum += candiates[i]
                path.append(candiates[i])
                backtracking(candiates, target, sum, i+1)
                path.pop()
                sum -= candiates[i]
        
        candiates = sorted(candiates)
        backtracking(candiates, target, 0, 0)
        return res
