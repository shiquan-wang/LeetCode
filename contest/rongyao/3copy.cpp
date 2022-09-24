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
        if(str[str.size() - 1] == '-'){
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
    string s = "-jik-";
    Solution s1;
    cout<<s1.op(s);
}