#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution{
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.second > b.second;
    }
    long long deal(vector<int>& vec){
        int n = vec.size();
        int maxodd = 0;
        int maxeven = 0;

        for(int i = 0; i < n; ++i){
            if(i % 2 == 1 && maxodd < vec[i]){
                maxodd = vec[i];
            }
            if(i % 2 == 0 && maxeven < vec[i]){
                maxeven = vec[i];
            }
        }

       
        long long sum = 0;
        for(int i = 0; i < n; ++i){
            if(i % 2 == 1){
                sum += abs(maxodd - vec[i]);
            }else{
                sum += abs(maxeven - vec[i]);
            }
        }
        if(maxodd != maxeven){
            return sum;
        }else{
            return sum + n/2;
        }

    }
    void get_ans(vector<vector<int>>& nums){
        int n = nums.size();
        vector<long long> ans;
        for(auto num: nums){
            long long temp = deal(num);
            ans.push_back(temp);
        }
        for(int i = 0; i < n-1; ++i){
            cout<<ans[i]<<endl;
        }
        cout<<ans[n-1];
    }
};
int main(){
    int T;
    cin>>T;
    Solution s1;
    vector<vector<int>> temp;
    for(int i = 0; i < T; ++i){
        int N;
        cin>>N;
        vector<int> vec;
        for(int j = 0; j < N; ++j){
            int item;
            cin>>item;
            vec.push_back(item);
        }
        temp.push_back(vec);
    }
    s1.get_ans(temp);
}