#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<string> score(vector<string>& vec){
        vector<string> ans;
        for(int i = 0; i < vec.size(); ++i){
            string temp = ou(vec[i]);
            ans.push_back(temp);
        }

        return ans;
    }
    string ou(string& str){
        int len = str.size();
        if((str[len-1] - '0') % 2 == 0){
            return str;
        }else{
            int i = 0;
            for(; i < len-1; ++i){
                if((str[i] - '0') % 2 == 0){
                    swap(str[i], str[len-1]);
                    return str;
                }
            }
            return "-1";
        }
    }
};

int main(){
    int q;
    cin>>q;
    vector<string> vec(q);
    for(int i = 0; i < q; ++i){
        cin>>vec[i];
    }
    Solution s1;
    vector<int> ans = s1.score(vec);
    for(auto item: ans){
        cout<<item<<" ";
    }
}