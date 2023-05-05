""" 
共有 n 位员工，每位员工都有一个从 0 到 n - 1 的唯一 id 。

给你一个二维整数数组 logs ，其中 logs[i] = [idi, leaveTimei] ：

idi 是处理第 i 个任务的员工的 id ，且
leaveTimei 是员工完成第 i 个任务的时刻。所有 leaveTimei 的值都是 唯一 的。
注意，第 i 个任务在第 (i - 1) 个任务结束后立即开始，且第 0 个任务从时刻 0 开始。

返回处理用时最长的那个任务的员工的 id 。如果存在两个或多个员工同时满足，则返回几人中 最小 的 id 。
"""
class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        ans, maxcost = logs[0]
        for i in range(1, len(logs)):
            id, cost = logs[i][0], logs[i][1] - logs[i-1][1]
            if cost > maxcost or (cost == maxcost and id < ans):
                ans, maxcost = id, cost
        return ans

