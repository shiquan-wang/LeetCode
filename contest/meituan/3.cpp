#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution{
public:
    void ans(vector<int>& nums){
        deque<int> dq;
        int ids = nums.size()-1;
        for(int i = 0; i < nums.size(); ++i){
            dq.push_back(nums[ids]);
            int j = 0;
            while (!dq.empty() && j < 2)
            {
                int temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
                j++;
            }
            ids --; 
        }
        cout<<dq.back();
        dq.pop_back();
        while (!dq.empty())
        {
            cout<<" "<<dq.back();
            dq.pop_back();
        }
    }
};

int main(){
    int n, item;
    vector<int> vec;
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>item;
        vec.push_back(item);
    }
    Solution s1;
    s1.ans(vec);
}