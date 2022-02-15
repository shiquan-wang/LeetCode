#include<iostream>
#include<vector>

using namespace std;
/* 
对于所有的数字，只有奇数和偶数两种：

奇数：二进制表示中，奇数一定比前面那个偶数多一个 1，因为多的就是最低位的 1。
偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。因为最低位是 0，除以 2 就是右移一位，也就是把那个 0 抹掉而已，所以 1 的个数是不变的。
所以我们可以得到如下的状态转移方程：

dp[i] = dp[i-1]，当i为奇数
dp[i] = dp[i/2]，当i为偶数
上面的方程还可进一步合并为：
dp[i] = dp[i/2] + i % 2

通过位运算进一步优化：

i / 2 可以通过 i >> 1 得到；
i % 2 可以通过 i & 1 得到；

 */
class Solution{
public:
    vector<int> countBits(int n){
        vector<int> res(n+1, 0);
        for(int i = 0; i <= n; ++i){
            res[i] = res[i >> 1] + (i & 1);
        }

        return res;
    }
};