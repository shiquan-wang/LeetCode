#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution{
public:
    void get_ans(vector<string>& nums, int k){
        string ans = "";
        for(auto item: nums){
            string str1 = item.substr(0, k-0);
            string str2 = item.substr(k+1, item.size() - k);
            ans += str1;
            ans += str2;
        }
        cout<<ans;
    }
};
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    vector<string> nums;
    int start = 0, end = 0;
    for(int i = 0; i < s.size(); ++i){
        end = i;
        if(s[i] == '-'){
            string str = s.substr(start, end - start);
            nums.push_back(str);
            start = i+1;
        }
    }
    nums.push_back(s.substr(start, s.size() - start));
    // for(auto item: nums){
    //     cout<<item<<endl;
    // }
    Solution s1;
    s1.get_ans(nums, k);

}