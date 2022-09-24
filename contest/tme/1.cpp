#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;


class Solution {
private:
    int ans;
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回满足题意的最小操作数
     * @param str string字符串 给定字符串
     * @return int整型
     */

    void dfs(vector<int>& vec){
        int count0 = 0, count1 = 0;
        for(int i = 0; i < 26; ++i){
            if(vec[i] == 0){
                count0++;
            }else{
                if(vec[i] % 2 == 0){
                    count0++;
                }
                count1 = count1+vec[i]/2;
            }
        }
        ans += count1;

        if(count1 <= count0){
            return;
        }else{
            count1 -= count0;
            for(int i = 0; i < 26; ++i){
                vec[i] = count1/26;
            }
            for(int i = 0; i < count1/26; ++i){
                vec[i] += 1;
            }
            dfs(vec);
        }
    }

    int minOperations(string str) {
        // write code here
        // unordered_map<char, int> up;
        vector<int> vec(26, 0);
        for(char ch: str){
            vec[ch - 'a']++;
        }
        ans = 0;
        dfs(vec);
        return ans;
    }
};