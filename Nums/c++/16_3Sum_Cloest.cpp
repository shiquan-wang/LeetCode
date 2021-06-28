#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//时间复杂度O(N*N) 空间复杂度O(N)
class Solution{
private:
    int bestsum = 1e7;

public:
    void update(int sum, int target){
        if(abs(target-sum)<abs(target-bestsum)){//如果当前sum更接近target，则更新bestsum
            bestsum = sum;
            cout<<bestsum;
        }
    }
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n; ++i){
            if(i>0 && nums[i]==nums[i-1]){//a重复则跳过
                continue;
            }

            for(int pb=i+1, pc=n-1; pb<pc; ){
                int sum= nums[i]+nums[pb]+nums[pc];
                update(sum, target);
                if(sum==target){//如果sum和target相等则直接返回
                    return target;
                }
                if(nums[pb]+nums[pc] >= target-nums[i]){
                    pc--;
                }else{
                    pb++;
                }
            }
        }

        return bestsum;

    }
};

int main(){
    vector<int> v = {-1, 2, 1, -4};
    int target = 1;
    Solution s;
    cout<<s.threeSumClosest(v, target);
}