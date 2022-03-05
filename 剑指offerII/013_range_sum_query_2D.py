""" 
给定一个二维矩阵 matrix, 以下类型的多个请求,

计算其子矩形范围内元素的总和,该子矩阵的 左上角 为 (row1,col1) ,右下角 为 (row2,col2)。
实现 NumMatrix 类:

NumMatrix(int[][] matrix)给定整数矩阵 matrix 进行初始化
int sumRegion(int row1, int col1, int row2, int col2)返回 左上角 (row1,col1)、右下角(row2,col2) 所描述的子矩阵的元素总和 。

 """

from typing import List



class NumMatrix:
    def __init__(self, matrix : List[List[int]]) -> None:
        m, n = len(matrix), (len(matrix[0]) if matrix else 0)
        self.sums = [[0] * (n + 1) for _ in range(m)]
        _sums = self.sums

        for i in range(m):
            for j in range(n):
                _sums[i][j+1] = _sums[i][j] + matrix[i][j]

    def sumRegion(self, row1 : int, col1 : int, row2 : int, col2 : int) -> int:
        _sums = self.sums

        total = sum(_sums[i][col2 + 1] - _sums[i][col1] for i in range(row1, row2 + 1))
        return total

#303区域检索和-数组不可变
# 参考链接 ： https://leetcode-cn.com/problems/range-sum-query-immutable/solution/jian-dan-wen-ti-xi-zhi-fen-xi-qian-tan-q-t2nz/
""" 
问题描述:
给定一个整数数组 nums处理以下类型的多个查询:

计算索引left和right包含 left 和 right之间的 nums 元素的 和 其中left <= right
实现 NumArray 类

NumArray(int[] nums) 使用数组 nums 初始化对象
int sumRange(int i, int j) 返回数组 nums中索引left和right之间的元素的 总和 包含left和right两点也就是nums[left] + nums[left + 1] + ... + nums[right]

基本思路:
每次遍历i到j进行累加,但如果查询次数过多会导致超时,因此在建立数组时进行处理,进行前缀和处理吗,这样才能将每次的查询用时降到O(1)上
具体地:
nums 数组的每一项都对应有它的前缀和: nums 的第 0 项到 当前项 的和。

用数组 preSum 表示,preSum[i]:第 0 项到 第 i 项 的和 preSum[i] = nums[0] + nums[1] + ... + nums[i]

易得,nums 的某项 = 两个相邻前缀和的差 nums[i] = preSum[i] - preSum[i-1]

因此 nums[i] + nums[i+1] + ... + nums[j] = preSum[j] - preSum[i-1]

当i = 0时,i-1 为-1,为了让上式成立, 使得preSum[-1] = 0 

sumRange[i, j] = preSum[j] - preSum[i-1]

特殊地:
为了不用特殊处理边界情况i=0的时候
定义 nums[i] + nums[i+1] + ... + nums[j] = preSum[j+1] - preSum[i]

那么 nums[i] = preSum[i+1] - preSum[i]

preSum[i+1] = nums[0] + nums[1] + ... + nums[i]

此时只需要让preSum[0] = 0即可使得所有的[i, j]满足 nums[i] + ... +nums[j] = preSum[j+1] - preSum[i]
 """
class NumMatrix2:
    def __init__(self, nums : List[int]) -> None:
        self.nums = [0]
        _sums = self.nums

        for num in nums:
            _sums.append(_sums[-1] + num)
    
    def sumRange(self, i : int, j : int) -> int:
        _sums = self.nums
        return _sums[j+1] - _sums[i]
