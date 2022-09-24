#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct cmp
{
    bool operator()(const pair<string, int>& a, const pair<string, int>& b){
        if(a.second != b.second){
            return a.second > b.second;
        }else{
            return a.first < b.first;
        }
    }
};


class Solution{
public:
    void get_ans(vector<string>& nums){
        // map<string, int> mp;
        unordered_map<string, int> mp;
        for(auto item : nums){
            mp[item] ++;
        }
        vector<pair<string, int>> vec;
        for(auto item: mp){
            vec.push_back({item.first, item.second});
        }
        sort(vec.begin(), vec.end(), cmp());
        cout<<vec[0].first;
    }
};
int main(){
    string s;
    cin>>s;
    vector<string> nums;
    int start = 0, end = 0;
    for(int i = 0; i < s.size(); ++i){

        end = i;
        if(s[i] == ','){
            string str = s.substr(start, end - start);
            // cout<<str<<endl;
            nums.push_back(str);
            // cout<<stoi(str);
            start = i+1;
            // cout<<"start0"<<start<<endl;
        }
    }
    nums.push_back(s.substr(start, s.size() - start));
    // for(auto item: nums){
    //     cout<<item<<endl;
    // }
    Solution s1;
    s1.get_ans(nums);

}