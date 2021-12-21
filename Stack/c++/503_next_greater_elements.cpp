#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    vector<int> nextGreaterElements(vector<int>& T){
        int n = T.size();
        vector<int> ans(n,-1);
        stack<int> s;
        for(int i = 0;i < n*2-1; i++){                            //不需要显性地将该循环数组「拉直」，而只需要在处理时对下标取模即可
            while(!s.empty() && T[i%n] > T[s.top()]){           
                ans[s.top()] = T[i%n]; 
                s.pop();
            }
            s.push(i%n);
        }
        return ans;
    }
        
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

class Solution2{
public:
    vector<int> nextGreaterElements(vector<int>& nums){
        vector<int> res(nums.size(), -1);
        stack<int> s;

        for(int i = 0; i < nums.size() * 2; ++i){
            /* while(!s.empty() && nums[i%nums.size()] > s.top()){
                s.pop();
            }
            res[i] = s.empty() ? -1 : s.top();
            s.push(nums[i%nums.size()]); */
            while(!s.empty() && nums[i%nums.size()] > nums[s.top()]){//单调栈中存放数据的下标，这样可以从前往后遍历，如果存放具体数值，需要用一个额外的map数组来完成映射。
                res[s.top()] = nums[i%nums.size()];
                s.pop();
            }
            s.push(i%nums.size());
        }
        return res;
    }
};
