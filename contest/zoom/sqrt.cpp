/* 
不使用库函数计算sqrt
 */
#include<iostream>

using namespace std;

class Solution{
public:
    double mysqrt(double x){
        double eps = 0.00000000001;
        if(x < 0){
            return -1.0;
        }
        double a = x/2, b = x / a;
        while (a - b > eps || b - a > eps)
        {
            /* code */
            b = x/a;//每次迭代先用原来的长x更新宽y
            a = (a+b)/2;//再更新长x（公式）
        }
        
    }
};