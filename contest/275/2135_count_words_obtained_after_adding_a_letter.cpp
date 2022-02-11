#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords){
        auto mask = [](const string& word) -> int{
            int res = 0;
            for(char ch : word){
                res |= 1 << (ch - 'a');
            }
            return res;
        };

        unordered_set<int> masks;
        for(const string& start: startWords){
            int msk = mask(start);
            for(int i = 0; i < 26; ++i){
                if(((mask >> i) & 1) == 0){
                    masks.insert(mask | (1 << i));
                }
            }
        }

        int cnt = 0;
        for(const string& target: targetWords){
            if(masks.count(mask(target))){
                ++cnt;
            }
        }
        return cnt;
    }
};