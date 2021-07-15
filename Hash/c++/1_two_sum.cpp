#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            
            if(mp.find(target - nums[i]) != mp.end()){
                return {mp.find(target - nums[i])->second, i};
            }
            // 不能先插入nums[i], i  这样会导致某一个元素使用两次的情况出现，比如： 3,2,4 target = 6  如果先插入3，再查找target-3 会找到刚插入的3
            // 所以要先在哈希表中查找再插入元素。
            mp.insert(pair<int, int>(nums[i], i));
        }
        return {};
        // mp.count(key)
        // mp.find(key)
        /* unordered_map<int, int>::iterator iter;
        iter = mp.begin(); iter = mp.end(); iter->first */
        
    }
};

int main(){
    vector<int> nums = {2, 7, 11, 15};
    Solution s;
    cout<<s.twoSum(nums, 9)[0]<<s.twoSum(nums, 9)[1];
}