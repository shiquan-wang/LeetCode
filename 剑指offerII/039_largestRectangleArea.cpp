#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
/* 
给定非负整数数组 heights ，数组中的数字用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

思路：使用单调递增栈来寻找以当前柱子高度为矩形高时的矩形的最大宽度，

栈中存放了 j(下标) 值。从栈底到栈顶，j 的值严格单调递增，同时对应的高度值也严格单调递增；

当我们枚举到第 i 根柱子时，我们从栈顶不断地移除 height[j]≥height[i] 的 j 值。在移除完毕后，栈顶的 j 值就一定满足 height[j]<height[i]，此时 j就是 i 左侧且最近的小于其高度的柱子。

这里会有一种特殊情况。如果我们移除了栈中所有的 j 值，那就说明 i 左侧所有柱子的高度都大于 height[i]，那么我们可以认为 i 左侧且最近的小于其高度的柱子在位置j=−1，它是一根「虚拟」的、高度无限低的柱子。
这样的定义不会对我们的答案产生任何的影响，我们也称这根「虚拟」的柱子为「哨兵」。

我们再将 i 放入栈顶。

 */
class Solution{
public:
    int largestRectangleArea(vector<int>& heights){
        stack<int> st;
        vector<int> left(heights.size());//记录每个柱子高度左边的的最远宽度
        vector<int> right(heights.size());//记录每个柱子高度右边的最远宽度
        int res = 0;

        for(int i = 0; i < heights.size(); ++i){
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        } 

        for(int j = heights.size() - 1; j >= 0; --j){
            while (!st.empty() && heights[st.top()] >= heights[j])
            {
                st.pop();
            }
            right[j] = st.empty() ? heights.size() : st.top();
            st.push(j);
        }

        for(int i = 0; i < left.size(); ++i){
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }

        return res;
        
    }
};