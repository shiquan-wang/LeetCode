#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution{
public:
    bool containsDuplicate(vector<int>& nums){
        unordered_set<int> st;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if(st.count(nums[i]) == 1){
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
        //st.find(key)  st.erase(key) st.clear() st.swap(st2) 
        // st.rehash(10) 设置槽位数 st.reserve(1000) 改变容器容量
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    cout<<s.containDuplicate(nums);
}