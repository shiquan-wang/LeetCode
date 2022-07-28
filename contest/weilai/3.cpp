#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct my_Node{
    int value;
    int index;
};

class Solution{
public:
    int longest_subsequence(vector<int> nums){
        //dp寻找最长递增子序列
        vector<int> dp(nums.size(), 0);
        int lengest = 1;
        dp[0] = 1;
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = 1;
            // for(int j = 0; j < i; ++j){
            //     if(nums[j] <= nums[i]){
            //         dp[i] = max(dp[i], dp[j] + 1);
            //     }
            // }
            if(nums[i] > nums[i-1]){
                dp[i] = dp[i-1] + 1;
            }
            lengest = max(lengest, dp[i]);
        }

        return lengest;
    }
    static bool cmp(my_Node a, my_Node b){//自定义升序排列, 要用静态成员函数的形式
        if(a.value < b.value){
            return true;
        }
        return false;
    }
    int operation(vector<int> nums){
        //最长递增子串，根据排序后的下标来求最长递增子串
        int n = nums.size();
        vector<my_Node> vec(n);
        for(int i = 0; i < n; ++i){//构建节点数据
            vec[i].value = nums[i];
            vec[i].index = i;
        }
        sort(vec.begin(), vec.end(), cmp);

        vector<int> indexs(n);//得到排序后的下标索引顺序
        for(int i = 0; i < n; ++i){
            indexs[i] = vec[i].index;
        }

        int lengest = longest_subsequence(indexs);
        return n - lengest;
    }
};

int main(){
    int N;
    cin>>N;
    vector<int> nums(N, 0);
    for(int i = 0; i < N; ++i){
        cin>>nums[i];
    }
    Solution s1;
    cout<<s1.operation(nums);
}