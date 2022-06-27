/* 
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
解法：
我们考虑枚举数组中的每个数 x，考虑以其为起点，不断尝试匹配 x+1, x+2,⋯ 是否存在，假设最长匹配到了 x+y，那么以 x 为起点的最长连续序列即为 x, x+1, x+2,⋯,x+y，其长度为 y+1，我们不断枚举并更新答案即可。

对于匹配的过程，暴力的方法是 O(n) 遍历数组去看是否存在这个数，但其实更高效的方法是用一个哈希表存储数组中的数，这样查看一个数是否存在即能优化至 O(1) 的时间复杂度。

仅仅是这样我们的算法时间复杂度最坏情况下还是会达到 O(n^2)（即外层需要枚举 O(n)个数，内层需要暴力匹配 O(n) 次），无法满足题目的要求。但仔细分析这个过程，我们会发现其中执行了很多不必要的枚举，
如果已知有一个 x, x+1, x+2, ⋯,x+y 的连续序列，而我们却重新从 x+1x+2 或者是 x+y 处开始尝试匹配，那么得到的结果肯定不会优于枚举 x 为起点的答案，因此我们在外层循环的时候碰到这种情况跳过即可。

那么怎么判断是否跳过呢？由于我们要枚举的数 xx 一定是在数组中不存在前驱数 x-1的，不然按照上面的分析我们会从 x-1 开始尝试匹配，因此我们每次在哈希表中检查是否存在 x-1 即能判断是否需要跳过了。

 */

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution{
public:
    int longestConsecutive(vector<int>& nums){\
        unordered_set<int> st;

        for(auto num : nums){//将nums去重插入哈希表中
            st.emplace(num);
        }

        int ans = 0;
        
        for(auto num : st){
            int curr_ans = 1;
            int curr_num = num;
            if(st.count(curr_num - 1) == 1){
                continue;
            }

            while (st.count(curr_num + 1) == 1)
            {
               curr_num++;
               curr_ans++;
            }
            ans = max(ans, curr_ans);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {100,  4, 200, 1, 3, 2};
    Solution s1;
    int res = s1.longestConsecutive(nums);
    cout<<res;
}