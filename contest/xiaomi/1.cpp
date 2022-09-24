#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void get_ans(vector<int>& nums, int x){
        int left = 0, right = 0;
        long lla = 0, oow = 0;
        for(auto item: nums){
            lla += item;
        }
        lla -= x;
        int ans = -1;
        while (1)
        {
            /* code */
            if(oow == lla){
                ans = max(ans, right - left);
                if(right < nums.size()){
                    oow += nums[right];
                    right ++;
                }else{
                    break;
                }
            }else if(oow < lla){
                if(right < nums.size()){
                    oow += nums[right];
                    right++;
                }else{
                    break;
                }
            }else{
                if(left < right){
                    oow = nums[left];
                    left++;
                }else{
                    break;
                }
            }
        }
        if(ans == -1){
            cout<<ans;
        }else{
            cout<<nums.size() - ans;
        }
        
    }
};
int main(){
    string s;
    cin>>s;
    int n, x;
    cin>>n;
    cin>>x;
    vector<int> nums;
    int start = 1, end = 1;
    for(int i = 1; i < s.size()-1; ++i){
        // if(s[i] == '['){
        //     continue;
        // }
        end = i;
        if(s[i] == ','){
            string str = s.substr(start, end - start);
            // cout<<str<<endl;
            nums.push_back(stoi(str));
            // cout<<stoi(str);
            start = i+1;
            // cout<<"start0"<<start<<endl;
        }
    }
    nums.push_back(stoi(s.substr(start, s.size() - start)));
    
    Solution s1;
    s1.get_ans(nums, x);
}