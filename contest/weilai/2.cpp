#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution{
public:
    unordered_map<int, int> get_zhiyinshu(int num){//分解质因数
        unordered_map<int, int> up;
        if(num % 2 != 0){
            up[num] = 1;
            return up;
        }
        for(int i = 2; i <= num; ++i){
            while (num % i == 0)
            {
                num /= i;
                up[i]++;
            }
            if(num == 1) break;
        }
        return up;
    }
    int operations(vector<int> nums){
        int N = nums.size();
        int ans = 0;

        vector<unordered_map<int, int>> vec;
        unordered_set<int> st;
        for(int i = 0; i < N; ++i){//遍历nums数组，分解质因数
            int num = nums[i];
            if(num == 1) continue;
            unordered_map<int, int> temp = get_zhiyinshu(num);
            vec.push_back(temp);
            for(pair<int, int> p : temp){//存储出现过的质因数
                if(st.count(p.first) == 0){
                    st.insert(p.first);
                }
            }
        }
        
        unordered_map<int, int> res;//存储每个质因数和它为奇数个的个数
        for(int item : st){
            int ji = 0;
            for(auto up1 : vec){
                if(up1.count(item) != 0){
                    if(up1[item] % 2 != 0){
                        ji++;
                    }
                }
            }
            ans += min(ji, N - ji);
        }
        return ans;
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
    cout<<s1.operations(nums);
}