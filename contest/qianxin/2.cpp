#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    void max_ares(vector<int> nums){
        
        int ans = -1;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            /* code */
            int temp = (right - left) * min(nums[left], nums[right]);
            ans = max(temp, ans);
            if(nums[left] <= nums[right]){
                left++;
            }else{
                right--;
            }
        }
        
        cout<<ans<<endl;
    }
};
int main(){
    vector<int> vec;
    int item;
    while (1)
    {
        // if(cin.get() == ','){
        //     continue;
        // }
        cin>>item;
        vec.push_back(item);
        if(cin.get() == '\n'){
            break;
        }
    }
    Solution s1;
    s1.max_ares(vec);
}