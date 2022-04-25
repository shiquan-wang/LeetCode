#include<iostream>
#include<vector>
#include<algorithm>
#include<set>//set内部是有序的，具体实现是二叉搜索树
using namespace std;
/* 
给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。

如果存在则返回 true，不存在返回 false

tips: static_cast<long>(a + b) static_cast 表达式的类型强制转换

根据题意，对于任意一个位置 i（假设其值为 u），我们其实是希望在下标范围为 [max(0, i - k), i)[max(0,i−k),i) 内找到值范围在 [u - t, u + t][u−t,u+t] 的数。

一个朴素的想法是每次遍历到任意位置 i 的时候，往后检查 k 个元素，但这样做的复杂度是 O(nk)O(nk) 的，会超时。

我们希望使用一个「有序集合」去维护长度为 k 的滑动窗口内的数，该数据结构最好支持高效「查询」与「插入/删除」操作：

    查询：能够在「有序集合」中应用「二分查找」，快速找到「小于等于 uu 的最大值」和「大于等于 u 的最小值」（即「有序集合」中的最接近 u 的数）。
    插入/删除：在往「有序集合」添加或删除元素时，能够在低于线性的复杂度内完成（维持有序特性）。


 */
class Solution{
public:
    bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t){
        if(nums.size() == 0) return false;
        bool flag = false;
        for(int i = 0; i < nums.size()-1; ++i){
            for(int j = i+1; j < nums.size(); ++j){
                
                if(abs(static_cast<long>(nums[i]) - nums[j]) <= t && abs(i - j) <= k){
                    flag = true;
                    return flag;
                }
            }
        }
        return flag;
    }
    //双指针
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
        int n = nums.size();
        set<int> rec;
        for(int i = 0; i < n; ++i){
            auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t);
            if(iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t){
                return true;
            }
            rec.insert(nums[i]);
            if(i >= k){
                rec.erase(nums[i - k]);
            }
        }
        return false;
    }
};