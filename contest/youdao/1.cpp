#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
    void res(vector<int> vec, int n){
        int ans = 0;
        vector<vector<int>> ans_vec;
        unordered_map<int, int> up;
        for(int i = 0; i < n; ++i){//构建value-index的映射
            up[vec[i]] = i;
        }
        for(int j = 0; j < n; ++j){
            while (vec[j] > j+1)
            {
                /* code */
                int i = up[vec[j] - 1];
                vec[j]--;
                vec[i]++;
                ans++;
                ans_vec.push_back({i+1, j+1});
                up[vec[j]] = j;
                up[vec[i]] = i;
            } 
        }
        cout<<ans<<endl;
        for(auto item: ans_vec){
            cout<<item[0]<<" "<<item[1]<<endl;
        }
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> vec;
    int item;
    for(int i = 0; i < n; ++i){
        cin>>item;
        vec.push_back(item);
    }
    Solution s1;
    s1.res(vec, n);
}