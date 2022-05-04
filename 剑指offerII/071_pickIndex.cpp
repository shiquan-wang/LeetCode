#include<iostream>
#include<vector>
#include<random>
using namespace std;
/* 
给定一个正整数数组 w ，其中 w[i] 代表下标 i 的权重（下标从 0 开始），请写一个函数 pickIndex ，它可以随机地获取下标 i，选取下标 i 的概率与 w[i] 成正比。

例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。

也就是说，选取下标 i 的概率为 w[i] / sum(w) 。

思路：
为题目给定的nums生成一个前缀和数组，以[1, 2, 3, 5]为例，其前缀和数组为[1, 3, 6, 11]，数组元素总和为11；

使用rand() % 11来生成一个0~10范围内的随机数，在前缀和数组中找到第一个严格大于它的数，那个数的下标就是我们要找的下标。因为权重越大的数，它所占据的区间范围越大（比如5所占据的区间为6~10），随机数也就越有可能落到它所在的区间内；

前缀和数组是有序的，有序数组中的查找可以使用二分法。
 */
class Solution{
private:
    vector<int> sums;
    int total = 0;
public:
    Solution(vector<int>& w){
        sums.resize(w.size());
        for(int i = 0; i < w.size(); ++i){
            total += w[i];
            sums[i] = total;
        }
    }

    int pickIndex(){
        int rnd = rand() % total;
        int left = 0, right = sums.size() - 1;
        while (left < right)
        {
            int mid = (right - left)/2 + left;
            if(rnd < sums[mid]){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};