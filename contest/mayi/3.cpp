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

        unordered_map<int, int> odd;
        unordered_map<int, int> even;
        for(int i = 0; i < n; ++i){
            if(i % 2 == 1){
                odd[vec[i]]++;
            }else{
                even[vec[i]]++;
            }
        }

        vector<pair<int, int>> odd_vec;
        vector<pair<int, int>> even_vec;
        for(auto item: odd){
            odd_vec.push_back(item);
        }
        for(auto item: even){
            even_vec.push_back(item);
        }
        sort(odd_vec.begin(), odd_vec.end(), cmp);
        sort(even_vec.begin(), even_vec.end(), cmp);
        
        int odd_num, even_num;
        if(odd_vec[0].first != even_vec[0].first){
            odd_num = odd_vec[0].first;
            even_num = even_vec[0].first;
        }else{
            odd_num = odd_vec[0].second > even_vec[0].second ? odd_vec[0].first : odd_vec[1].first;
            even_num = odd_vec[0].second > even_vec[0].second ? even_vec[0].first : even_vec[1].first;
        }

        long long sum = 0;
        for(int i = 0; i < n; ++i){
            if(i % 2 == 1){
                sum += abs(odd_num - vec[i]);
            }else{
                sum += abs(even_num - vec[i]);
            }
        }
        return sum;
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