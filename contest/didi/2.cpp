#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
    int get_b(int num){
        int y = 0;
        while (num != 0)
        {
            /* code */
            y = y ^ (num%10);
            num /= 10;
        }
        return y;
    }
public:
    // vector<int> b_nums;
    // void get_b_nums(){
    //     b_nums.resize(70000);
    //     for(int i = 0; i < 70000; ++i){
    //         b_nums[i] = get_b(i);
    //     }
    // }

    int get_bnum(int left, int right, int t){
        int ans = 0;
        for(int i = left; i <= right; ++i){
            if(get_b(i) == t){
                ans++;
            }
        }
        return ans;
    }
};
int main(){
    int N;
    cin>>N;
    vector<int> left;
    vector<int> right;
    vector<int> t;
    int item;
    for(int i = 0; i < N; ++i){
        cin>>item;
        left.push_back(item);
    }
    for(int i = 0; i < N; ++i){
        cin>>item;
        right.push_back(item);
    }
    for(int i = 0; i < N; ++i){
        cin>>item;
        t.push_back(item);
    }
    Solution s;
    // s.get_b_nums();
    vector<int> ans;
    for(int i = 0; i < N; ++i){
        int temp = s.get_bnum(left[i], right[i], t[i]);
        ans.push_back(temp);
    }
    for(int i = 0; i < ans.size() - 1; ++i){
        cout<<ans[i]<<" ";
    }
    cout<<ans[ans.size()-1];
}