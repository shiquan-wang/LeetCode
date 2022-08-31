#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution{
public:
    int res(string str){
        unordered_map<char, int> mp;
        int ans = 0;
        for(int i = 0; i < str.size(); ++i){
            mp['r'] = 0; mp['e'] = 0; mp['d'] = 0;
            for(int j = i+1; j < str.size(); ++j){
                mp[str[j]]++;
                if(check(mp)){
                    ans++;
                }
            }
        }
        return ans;
    }
    bool check(unordered_map<char, int> mp){
        bool flag = true;
        int target = mp['r'];
        for(auto item : mp){
            if(item.second != target){
                flag = false;
                break;
            }
        }
        return flag;      
    }
};
int main(){
    string str;
    cin>>str;
    Solution s1;
    cout<<s1.res(str);
}