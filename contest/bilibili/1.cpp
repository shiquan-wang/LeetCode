#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_set>
using namespace std;

class Solution{
public:
    void get_ans(vector<int>& nums){
        int ans = 0;
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); ++i){
            int temp = log(nums[i])/log(2);
            st.insert(temp);
        }
        cout<<st.size()<<endl;
    }
};
int main(){
    int M;
    cin>>M;
    Solution s1;
    for(int i = 0; i < M; ++i){
        vector<int> vec;
        int n, item;
        cin>>n;
        for(int i = 0; i < n; ++i){
            cin>>item;
            vec.push_back(item);
        }
        s1.get_ans(vec);
    }
}