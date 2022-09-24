#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution{
public:
    int deal(string& str){
        return 0;
    }
    void get_ans(vector<string>& nums){
        int n = nums.size();
        vector<int> ans;
        for(auto num: nums){
            int temp = deal(num);
            ans.push_back(temp);
        }
        for(int i = 0; i < n-1; ++i){
            cout<<ans[i]<<endl;
        }
        cout<<ans[n-1];
    }
};
int main(){
    int N;
    cin>>N;
    Solution s1;
    vector<string> vec;
    for(int i = 0; i < N; ++i){
        string item;
        cin>>item;
        vec.push_back(item);
    }
    s1.get_ans(vec);
}