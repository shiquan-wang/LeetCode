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
