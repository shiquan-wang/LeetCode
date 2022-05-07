#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/* 
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

思路：大根堆，
 */
class Solution{
public:
    int findKthLargest(vector<int>& nums, int k){
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int item : nums){
            pq.push(item);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};