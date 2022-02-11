#include<iostream>
#include<vector>
#include<vector>

using namespace std;
/* 
银行内部的防盗安全装置已经激活。给你一个下标从 0 开始的二进制字符串数组 bank ，表示银行的平面图，这是一个大小为 m x n 的二维矩阵。 bank[i] 表示第 i 行的设备分布，由若干 '0' 和若干 '1' 组成。'0' 表示单元格是空的，而 '1' 表示单元格有一个安全设备。

对任意两个安全设备而言，如果同时 满足下面两个条件，则二者之间存在 一个 激光束：

两个设备位于两个 不同行 ：r1 和 r2 ，其中 r1 < r2 。
满足 r1 < i < r2 的 所有 行 i ，都 没有安全设备 。
激光束是独立的，也就是说，一个激光束既不会干扰另一个激光束，也不会与另一个激光束合并成一束。

返回银行中激光束的总数量。
 */
class Solution{
public:
    int numberOfBeams(vector<string>& bank){
        int m = bank.size(), n = bank[0].size();//n=bank[0].size()，数组越界时写的是bank[1].size(),太蠢了！！！
        if(m == 1) return 0;

        vector<int> count(m, 0);
        int pre = 0, cur = 0;
        int count_num = 0;
        for(int i = 0; i < m; ++i){//遍历行
            for(int j = 0; j < n; ++j){//遍历列
                if(bank[i][j] == '1') {
                    count[i]++;//统计每一行的设备数量
                }
            }

            if(count[i] > 0) {
                cur = count[i];
                count_num += (pre * cur);
                pre = cur;
            }
        }
        return count_num;
    }
};
int main(){
    vector<string> bank = {"011001","000000","010100","001000"};
    vector<string> bank2 = {"0"};
    Solution s; 
    int res = s.numberOfBeams(bank2);
    cout<<res;
}