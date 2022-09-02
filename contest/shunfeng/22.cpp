/* 
小明有一个由1到n的整数组成的排列，他让你来猜出这个排列是什么。你每次可以猜测某一位置的数字，
小明会告诉你所猜测的数是“大了”、“小了”或是“正确”。你想知道你在最坏情况下，需要猜测几次，
才能在排列的所有位置都得到小明“正确”的回复？
 */
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution{
public:
    int search(int n){
        int ans = 0;
        ans += n;
        while (n > 1)
        {
            int left_index = int(log(n)/log(2));
            // int temp = 1<<left_index;
            int temp = pow(2, left_index);
            ans += (n - temp + 1) * left_index;
            n = temp - 1;
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    Solution s1;
    cout<<s1.search(n);
}