#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
/* 
给定一个整数数组 nums 和一个整数 k ，请返回其中出现频率前 k 高的元素。可以按 任意顺序 返回答案。
思路：使用哈希表存储数字及其出现的频率，由于哈系表不存在排序功能，因此再使用优先队列建立小根堆保存出现频率高的前k个元素。
重点内容：构建优先队列时小根堆的比较函数可以使用仿函数来写
 */
class Solution{
private:
    // bool cmp(pair<int, int>& a, pair<int, int>& b){
    //     return a.second > b.second;
    // }
    struct mycmp//定义仿函数用于优先队列构建小根堆
    {
        bool operator()(pair<int, int>& p1, pair<int, int>& p2){
            return p1.second > p2.second;
        }
    };
    
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> pq;//小根堆存储数字及其出现的频率
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> res;
        for(auto iter : nums){//使用哈希表存储数字以及它出现的次数
           mp[iter]++;
        }
        // for(auto iter = mp.begin(); iter != mp.end(); ++iter) {
            
        // }
        for(auto iter : mp){//遍历map,将数据存储到优先队列中，
        //1, 先将iter存放在pq中
        //2， 判断当前优先队列元素个数是否超过k,若超过则将队首元素出队
            pq.push(iter);
            if(pq.size() > k){
                pq.pop();
            }
        }

        while (!pq.empty())//遍历优先队列，将出现频率高的前k个元素返回
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
    }

    void add_to_pq(){

    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    s.topKFrequent(nums, 2);
}