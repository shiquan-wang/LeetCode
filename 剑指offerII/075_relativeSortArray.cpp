#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/* 
Lambda表达式完整的声明格式如下：
[capture list] (params list) mutable exception-> return type { function body }
 */
class Solution{
private:
    bool mycmp(int x, int y){

    }
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2){
        unordered_map<int, int> rank;
        for(int i = 0; i < arr2.size(); ++i){
            rank[arr2[i]] = i;
        }

        sort(arr1.begin(), arr1.end(), [&](int x, int y) ->bool {
            if(rank.count(x)){//x出现在arr2中
                return rank.count(y) ? rank[x] < rank[y] : true;//如果y在arr2中也出现，则根据二者在arr2中出现的顺序排序
            }else{
                return rank.count(y) ? false : x < y;//
            }
        });

        return arr1;
    }
};