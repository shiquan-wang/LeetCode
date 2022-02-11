#include<iostream>
#include<vector>

using namespace std;
//二进制
//给定两个整数 a 和 b ，求它们的除法的商 a/b ，要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%'
//基本思路：使用减法替代除法，每次减去一个b
//优化思路：当被除数大于除数时，继续判断是不是大于除数的 2 倍？ 4 倍？ 8 倍？....如果被除数大于除数的 2^k 倍，那么将被除数减去除数的 2^ k 倍，之后再重复以上步骤

//特殊的：上述分析过程都是基于被除数和除数都是正整数，如果存在负整数则可以将他们先转化为正整数进行计算，最后根据符号调整结果。
//但是对于 32 位 int 来讲，最大的正数为 2^31-1,最小的负数为 -2^31,如果将负数转化为正数会溢出，所以可以将正数都转化为负数计算，
//核心部分就是对两个负数进行除法，返回的结果可以用无符号数返回，最后进行正负号调整。
//另外所有的结果中存在一种情况无法用 int 表示结果，那就是被除数为 -2^31，除数为 -1，这时候直接特殊判断输出 INT_MAX 就行

class Solution{
private:
    int divideCore(int a, int b){
        int res = 0;
        while (a <= b)//a 与b 都已经转换为负数了
        {
            /* code */
            int value = b;
            unsigned int quo = 1;
            while(value >= 0xc0000000 && a <= value + value){
                quo += quo;
                value += value;
            }
            res += quo;
            a -= value;
        }
        return res;
    }
public:
    int divide(int a, int b){
        if(a == INT_MIN && b == -1){
            return INT_MAX;
        }

        int negative = 2;
        if(a > 0){
            negative--;
            a = -a;
        }

        if(b > 0){
            negative--;
            b = -b;
        }
        unsigned int res = divideCore(a, b);
        return negative == 1 ? -res : res;
    }
};