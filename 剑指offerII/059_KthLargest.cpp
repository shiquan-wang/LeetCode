#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
/* 
设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。

请实现 KthLargest 类：

    KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
    int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
思路：基本思路，每次插入后将数组进行排序，然后返回nums[k-1],问题在于每次调用add函数再进行排序会导致超出时间限制
问题存在的原因是数组不自带排序功能，使用sort排序时间复杂度过高
改进思路：使用自带排序功能的数据结构-堆
1，使用大小为K的小根堆，初始化时保证堆内的元素个数不超过K
2，每次add时，将新元素push()到堆中，如果堆内元素超过K，将元素中的最小元素pop()出栈（每次出栈的都是最小元素，大的元素一直在小根堆中保存着
3，此时堆内最小元素就是数据流中第K大元素
 */
class KthLargest{
private:
    // struct cmp{
    //     bool operator()(const int& x, const int& y){
    //         return x > y;
    //     }
    // };
    // priority_queue<int, vector<int>, cmp> pq;
    // int limit;
    priority_queue<int, vector<int>, greater<int>> pq;
    int limit;
public:
    // KthLargest(int k, vector<int>& nums){
    //     limit = k;
    //     for(const auto &item : nums){
    //         if(pq.size() < k){//优先队列还没有到k个元素
    //             pq.emplace(item);
    //             continue;
    //         }
    //         if(item > pq.top()){//优先队列
    //             pq.pop();
    //             pq.emplace(item);
    //         }
    //     }
    // }

    // int add(int val){
    //     if(pq.size() < limit){
    //         pq.emplace(val);
    //     }else if(val > pq.top()){
    //         pq.pop();
    //         pq.emplace(val);
    //     }

    //     if(pq.size() < limit) return 0;
    //     return pq.top();
    // }

    KthLargest(int k, vector<int> nums){
        limit = k;
        for(auto iter : nums){
            add(iter);
        }
    }

    int add(int val){
        pq.push(val);
        if(pq.size() > limit){
            pq.pop();
        }
        return pq.top();
    }
};