#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution{
public:
    string op(string str){
        string ans = "";
        if(str[0] == '-'){
            str.erase(0, 1);
        }
        if(str[1] == '-'){
            str.erase(str.size()- 1, 1);
        }
        return str;
    }
    void get_ans(vector<string>& nums){
        string ans = "";
        for(int i = nums.size()-1; i >= 0; ++i){
            if(nums[i] == " "){
                continue;
            }else{

            }
        }
    }
};
bool is_valid(char ch){
    if(isalpha(ch) || isdigit(ch) || ch == ' '){
        return true;
    }else{
        return false;
    }
}
bool index_valid(int i, int len){
    if(i >= 0 && i < len){
        return true;
    }else{
        return false;
    }
}
int main(){
    string s;
    getline(cin, s);
    
    vector<string> nums;
    //去除非法字符
    string s_deal = "";
    for(int i = 0; i < s.size(); ++i){
        if(is_valid(s[i]) || s[i] == '-'){
            s_deal += s[i];
            continue;
        }
    }
    // cout<<s_deal;
    int start = 0, end = 0;
    for(int i = 0; i < s_deal.size(); ++i){
        end = i;
        if(s_deal[i] == ' '){
            string str = s_deal.substr(start, end - start);
            nums.push_back(str);
            start = i+1;
            continue;
        }
        if(s_deal[i] == '-'){
            if(i+1 < s_deal.size() && s_deal[i+1] == '-'){//双--是分割符
                string str = s_deal.substr(start, end - start);
                nums.push_back(str);
                i++;
                start = i+1;
                continue;
            }
        }
    }
    nums.push_back(s_deal.substr(start, s.size() - start));
    for(auto item: nums){
        cout<<item<<endl;
    }
    Solution s1;

}