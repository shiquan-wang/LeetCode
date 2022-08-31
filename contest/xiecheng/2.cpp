#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<int> score(vector<vector<int>>& vec){
        vector<int> ans;
        for(int i = 0; i < vec.size(); ++i){
            int temp = get_score(vec[i]);
            ans.push_back(temp);
        }
        return ans;
    }
    int get_score(vector<int> vec){
        // unordered_map<int, int> up;
        int min_y = 0, ans = 0;
        // for(int i = 0; i < vec.size(); ++i){
        //     if(up.count(vec[i]) == 0){
        //         up[vec[i]] = 1;
        //     }else{
        //         up[vec[i]]++;
        //     }
        //     min_y = min(min_y, up[vec[i]]);
        // }
        for(int i = 0; i < vec.size(); ++i){
            min_y = min(min_y, vec[i]);
        }
        ans += 2*min_y;
        int min_o = 0;
        for(int i = 0; i < vec.size(); ++i){
            vec[i] -= min_y;
            min_o = min(min_o, vec[i]);
        }
        ans += min_o/2;
        return ans;
    }
};

int main(){
    int q;
    cin>>q;
    vector<vector<int>> vec(q, vector<int>(3));
    for(int i = 0; i < q; ++i){
        cin>>vec[i][0]>>vec[i][1]>>vec[i][2];
    }
    Solution s1;
    vector<int> ans = s1.score(vec);
    for(auto item: ans){
        cout<<item<<" ";
    }
}