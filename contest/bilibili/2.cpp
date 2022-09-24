#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_set>
using namespace std;

class Solution{
public:
    void get_ans(vector<int>& nums){
        int n = nums.size();
        vector<int> vec(n, -1);
        // vec[0] = INFINITY;
        for(int i = 1; i < n; ++i){
            for(int j = i-1; j >= 0; ++j){
                if(nums[j] > nums[i]){
                    vec[i] = nums[j];
                    break;
                }
            }
        }
        for(int i = 0; i < vec.size()-1; ++i){
            if(vec[i] == -1){
                // cout<<"INF"<<" ";
                printf("INF ");
                // printf(" ");
            }else{
                printf("%d ", vec[i]);
            }
        }
        printf("%d", vec[n-1]);
        
    }
};
int main(){
    int M;
    cin>>M;
    Solution s1;
    for(int i = 0; i < M; ++i){
        int n, item;
        cin>>n;
        vector<int> vec(n);
        for(int i = 0; i < n; ++i){
            cin>>item;
            vec[i] = item;
        }
        s1.get_ans(vec);
    }
}