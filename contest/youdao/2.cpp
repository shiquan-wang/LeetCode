#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
public:
    int res(string str){
        int ans = 0;
        unordered_map<char, int> up;
        up['r'] = 0;
        up['e'] = 0;
        up['d'] = 0;
        int min_num = 0;
        for(int i = 0; i < str.size(); ++i){
            up[str[i]]++;
        }
        for(auto item: up){
            min_num = min(item.second, min_num);
        }
        for(int i = 0; i < min_num; ++i){
            int k = i*3;
            int left = 0, right = k-1;
            vector<int> nums(3, 0);
            
            while (right < str.size())
            {
                /* code */
                bool flag = true;
                nums[0] = 0; nums[1] = 0; nums[2] = 0;
                for(int j = left; j <= right; ++j){
                    if(str[j] == 'r'){
                        nums[0]++;
                    }else if(str[j] == 'e'){
                        nums[1]++;
                    }else{
                        nums[2]++;
                    }
                    if(nums[0] > i|| nums[1] > i || nums[2] > i){
                        flag = false;
                        break;
                    }
                }
                if(flag == true){
                    ans++;
                }
                left++;
                right++;
            }
            
        }
        return ans;
    }
};
int main(){
    string s;
    cin>>s;
    Solution s1;
    cout<<s1.res(s);
}