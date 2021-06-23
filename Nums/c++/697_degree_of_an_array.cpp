#include <iostream>
#include <vector>
#include <map>

using namespace std;

 class Solution{
    public:
    int findShortestSubArray(vector<int>& nums){
         //key ：数字， value:出现的总次数，第一次出现的位置，最后一次出现的位置
        map<int, vector<int>> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            
            if(mp.count(nums[i])){ //不是第一次出现
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }else {
                mp[nums[i]] = {1, i, i};//第一次出现
            }
        }

        int maxnum = 0, minlen = 0; //maxnum 出现的最大次数， minlen 出现最多数的最小子序列长度
        map<int, vector<int>> :: iterator iter;

        iter = mp.begin();

        while(iter != mp.end()){
            if(iter->second[0] > maxnum){ //出现的次数最大
                maxnum = iter->second[0];
                minlen = iter->second[2] - iter->second[1] + 1;

            }else if(iter->second[0] == maxnum){//出现次数等于最大出现次数
                if((iter->second[2] - iter->second[1] + 1) < minlen){ //但是子序列长度更小
                    minlen = iter->second[2] - iter->second[1] + 1;
                }
            }
            iter++;
        } 
      return minlen;
    }
}; 

class Solution1 {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, vector<int>> mp;
        int n = nums.size();
        cout<<n;
        for (int i = 0; i < n; i++) {
            cout<<i;
            if (mp.count(nums[i])) {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            } else {
                mp[nums[i]] = {1, i, i};
            }
        }
        int maxNum = 0, minLen = 0;
        for (auto& [_, vec] : mp) {
            if (maxNum < vec[0]) {
                maxNum = vec[0];
                minLen = vec[2] - vec[1] + 1;
            } else if (maxNum == vec[0]) {
                if (minLen > vec[2] - vec[1] + 1) {
                    minLen = vec[2] - vec[1] + 1;
                }
            }
        }
        return minLen;
    }
};



int main(){
    vector<int> v = {1,2,2,3,1};
    Solution s;
    cout<<s.findShortestSubArray(v);
}