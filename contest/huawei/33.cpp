#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


class Solution{
public:
    static bool cmp2(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }
    bool check(vector<int>& vis, int index, vector<int>& position, vector<int>& radius){
        for(int i = position[index] - radius[index]; i < position[index] + radius[index]; ++i){
            if(i == position[index] - radius[index] || i == position[index] + radius[index]){
                continue;
            }
            if(vis[i] == 1){
                return false;
            }
        }
        return true;
    }
    void get_max_value2(vector<int>& position, vector<int>& radius, vector<int>& value){
        int n = position.size();
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; ++i){
            vec.push_back({i, position[i]});
        }
        sort(vec.begin(), vec.end(), cmp2);

        vector<int> vis(position[n-1] + radius[n-1], 0);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(check(vis, vec[i].first, position, radius)){
                ans += value[vec[i].first];
                for(int j = position[vec[i].first] - radius[vec[i].first]; j <= position[vec[i].first] + radius[vec[i].first]; ++j){
                    vis[j] = 1;
                }
            }
        }
        cout<<ans;
    }
};
int main(){
    int N;
    cin>>N;
    Solution s1;
    vector<int> position;
    vector<int> radius;
    vector<int> value;
    int item;
    for(int i = 0; i < N; ++i){
        cin>>item;
        position.push_back(item);
    }
    for(int i = 0; i < N; ++i){
        cin>>item;
        radius.push_back(item);
    }
    for(int i = 0; i < N; ++i){
        cin>>item;
        value.push_back(item);
    }
    s1.get_max_value(position, radius, value);
}