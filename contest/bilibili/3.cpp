#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_set>
using namespace std;

class Solution{
public:
    pair<int, int> deal(pair<int, int> a, pair<int, int> b){
        return{b.first + a.first, a.second * b.second};
    }
    void get_ans(string& str){
        vector<pair<int, int>> vec;
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == '(' || str[i] == ')' || str[i] == 'x'){
                continue;
            }
            string temp = str.substr(i, 2);
            vec.push_back({1, stoi(temp)});
            i++;
        }
        // for(auto item: vec){
        //     cout<<item.first<<" "<<item.second<<endl;
        // }
        pair<int, int> ans;
        ans = vec[0];
        for(int i = 1; i < vec.size(); ++i){
            ans = deal(ans, vec[i]);
        }
        cout<<ans.first;
    }
};
int main(){
    string str;
    cin>>str;
    Solution s1;

    s1.get_ans(str);
}