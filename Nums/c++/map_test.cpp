#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    //int map_iter()
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

int main(){
    map<int, vector<int>> mp;
    for(int i=0; i<5; ++i){
        mp[i] = {i, i*i};
    }
    //cout<<mp[2];
    map<int, vector<int>> :: iterator iter;
    iter = mp.begin();
    //cout<<iter->first<<iter->second;
    while(iter != mp.end()){
        cout<<iter->second[0]<<iter->second[1]<<endl;
        iter++;
    }
}