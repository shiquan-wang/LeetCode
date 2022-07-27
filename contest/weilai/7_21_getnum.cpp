/* 第一题添数博弈 */
/* 
1.博弈
池中一开始有两个数，可以从池中任意取两个数，两数之差的绝对值若不在池中可以放入，若在池中不能放入
小A和小B轮流玩，每轮需要如上规则放入一个两数之差，怎么操作都不能放入，则视为失败
 */
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
private:
    unordered_set<int> st;
public:
    int get_num(int x, int y){
        //辗转相除法求x和y的最大公约数
        int z = y;
        while (x % y != 0)
        {
            z = x % y;
            x = y;
            y = z;
        }
        return z;
    }
    int A_succ(int x, int y){
        // int num = 0;
        // int temp = x - get_num(x, y) * y;
        // x = y;
        // y = temp;
        if((x / get_num(x, y)) % 2 == 0){
            cout<<"B"<<endl;
        }else{
            cout<<"A"<<endl;
        }
        
    }
};

int main(){
    int T;
    cin>>T;
    int x, y;
    while (T--)
    {
        Solution s1;
        cin>>x>>y;
    }
    
}