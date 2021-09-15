#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        vector<int> temp(gas.size());
        for(int i = 0; i < temp.size(); ++i){
            temp[i] = gas[i] - cost[i];
        }
        int start_index, res;
        for(int i = 0; i < temp.size(); ++i){
            if(temp[i] < 0) continue;//起始站点剩余油量不能小于0
            // res = start_index = i; tank = 0;
            // for(int j = 0; j < temp.size(); ++j){
            //     tank += temp[start_index];
            //     if(tank < 0) break;
            //     start_index = (start_index+1)%temp.size();
            // }
            //for循环适合从头到尾的遍历，while适合环形遍历
            start_index = i+1; res = temp[i];
            while(res >= 0 && start_index != i){
                res += temp[start_index];
                start_index = (start_index+1) % temp.size();
            }
            if(start_index == i && res >= 0) return i;
        }
        return -1;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {   // 当前累加rest[i]和 curSum一旦小于0
                start = i + 1;  // 起始位置更新为i+1
                curSum = 0;     // curSum从0开始
            }
        }
        if (totalSum < 0) return -1; // 说明怎么走都不可能跑一圈了
        return start;
    }
};
int main(){
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    Solution s1;
    cout<<s1.canCompleteCircuit(gas, cost);
}