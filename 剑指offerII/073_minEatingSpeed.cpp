#include<iostream>
#include<vector>

using namespace std;
/* 
狒狒喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。

狒狒可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉，下一个小时才会开始吃另一堆的香蕉。  

狒狒喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）
思路：二分查找，从0-数组的最大值中找到k,k最小时即可
 */
class Solution{
private:
    bool is_eat(vector<int>& piles, int h, int k){
        int time = 0;
        for(int pile : piles){
            time += (pile-1) / k + 1;//或者(pile / k) + (pile % k) != 0, 
            //这么写是错误的(pile / k) + 1;， 当pile == k 时， 会多用一个小时的时间//每一堆香蕉消耗的时间
        }
        return time <= h;//吃掉香蕉的时间小于警卫回来的时间，返回true
    }
public:
    int minEatingSpeed(vector<int>& piles, int h){
        int l = 1, r = pow(10, 9);//二分查找的左右边界，最大值10^9，这样可以避免每次从数组中寻找最大值作为右边界

        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            if(is_eat(piles, h, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};