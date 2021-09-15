#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    bool lemonadeChange(vector<int>& bills){
        vector<int> res = {0, 0, 0};
        for(auto i : bills){
            if(i == 5) {//顾客给了5元
                res[0] += 1;
            }
            else if(i == 10) {//顾客给了10元
                res[1] += 1;
                if(res[0] <= 0){//5元不足来找零
                    return false;
                }
                res[0] -= 1;
            }
            else {//顾客给了20元
                res[2] += 1;
                if(res[1] > 0){//有10元纸币
                    if(res[0] <= 0){//没有5元纸币
                        return false;
                    }
                    res[1] -= 1;
                    res[0] -= 1;
                }else{//没有10元纸币
                    if(res[0] <= 2){//没有3张5元纸币
                        return false;
                    }
                    res[0] -= 3;
                }
            }
        }
        return true;
    }
};