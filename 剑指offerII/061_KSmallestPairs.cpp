#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
/* 
给定两个以升序排列的整数数组 nums1 和 nums2 , 以及一个整数 k 。
定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。

思路：
将数对组合，存储后。使用优先队列建立小根堆进行排序，可以在使用优先队列时判断当前数对和和栈顶和来进行剪枝
 */
class Solution{
private:
    struct mycmp//定义仿函数进行优先队列小根堆的构建
    {
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            return a.first+a.second < b.first+b.second;
        }
    };
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> pq;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
        vector<pair<int, int>> vec;
        for(int i = 0; i < nums1.size(); ++i){//存储所有存在的组合数对
            for(int j = 0; j < nums2.size(); ++j){
                vec.push_back(pair<int, int>(nums1[i], nums2[j]));
            }
        }

        for(auto iter : vec){
            pq.push(iter);
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> res;
        while (!pq.empty())
        {
            vector<int> temp;
            temp.push_back(pq.top().first);
            temp.push_back(pq.top().second);
            res.push_back(temp);
            pq.pop();
        }

        return res;   
    }
};