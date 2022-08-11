#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution{
public:
    int trap1(vector<int>& height){
        //双指针法，按照列来计算，把每一列可以存放雨水的深度算出来，因为宽度都是一，所以可以得出总的雨水体积。
        //每一列雨水的高度取决于左右两边的最低高度，最低处就是该列本身的高度，两者的差就是该列雨水的深度
        int res = 0;
        for(int i = 0; i < height.size(); ++i){
            if(i == 0 || i == height.size() - 1) continue;//第一个柱子和最后一个柱子接不到雨水

            int left = height[i];
            int right = height[i];
            for(int l = i-1; l >= 0; --l){
                if(height[l] > left) left = height[l];//左边的最大高度
            }
            for(int r = i+1; r < height.size(); ++r){
                if(height[r] > right) right = height[r];//右边的最大高度
            }
            int h = min(left, right) - height[i];

            res += h > 0 ? h : 0;
        }
        return res;
    }// O(n ^ 2)
    int trap2(vector<int>& height){
    //当前列雨水面积：min(左边柱子的最高高度，记录右边柱子的最高高度) - 当前柱子高度
    //为了得到两边的最高高度，使用了双指针来遍历，每到一个柱子都向两边遍历一遍，这其实是有重复计算的。
    //我们把每一个位置的左边最高高度记录在一个数组上（maxLeft），右边最高高度记录在一个数组上（maxRight）。这样就避免了重复计算，这就用到了动态规划。
    //当前位置，左边的最高高度是前一个位置的左边最高高度和本高度的最大值。
    //即从左向右遍历：maxLeft[i] = max(height[i], maxLeft[i - 1]);
    //从右向左遍历：maxRight[i] = max(height[i], maxRight[i + 1]);
        int res = 0;
        if(height.size() <= 2) return 0;
        vector<int> maxleft(height.size(), 0);
        vector<int> maxright(height.size(), 0);
        int size = height.size();
        // 记录每个柱子左边柱子最大高度
        maxleft[0] = height[0];
        for(int i = 1; i < size; ++i){
            maxleft[i] = max(height[i], maxleft[i-1]);
        }

        // 记录每个柱子右边柱子最大高度
        maxright[size - 1] = height[size - 1];
        for(int i = size - 2; i >= 0; --i){
            maxright[i] = max(height[i], maxright[i + 1]);
        }

        for(int i = 0; i < size; ++i){
            int count = min(maxleft[i], maxright[i]) - height[i];
            if(count > 0) res += count;
        }

        return res;
    }//O(n)

    int trap3(vector<int>& height){
        //单调栈，按行来计算雨水体积。
        stack<int> st;//单调栈用来存储下标,然后长通过柱子的高度来计算，宽通过柱子之间的下标来计算。
        st.push(0);
        int res = 0;

        for(int i = 1; i < height.size(); ++i){
            if(height[i] < height[st.top()]){//当前高度小于栈顶高度，满足递增栈，入栈
                st.push(i);
            }else if(height[i] == height[st.top()]){//当前高度等于栈顶高度，替换栈顶元素，因为计算体积时肯定使用的是最右边的柱子高度
                st.pop();
                st.push(i);
            }else{
                while(!st.empty() && height[i] > height[st.top()]){//当前高度大于栈顶高度，凹槽形成，可以接到雨水，找到左边第一个不小于当前柱子高度的柱子，它们之间就形成了一个凹槽。
                    int mid = st.top();
                    st.pop();
                    if(!st.empty()){
                        int h = min(height[i], height[st.top()]) - height[mid];
                        int w = i - st.top() - 1;
                        res += h * w;
                    }
                }
            }
        }
        return res;
    }

    int trap(vector<int>& height){
        stack<int> st;//单调栈用来存储下标
        st.push(0);
        int sum = 0;
        for(int i = 1; i < height.size(); ++i){
            if(height[i] < height[st.top()]){
                st.push(i);
            }else if(height[i] == height[st.top()]){
                st.pop();
                st.push(i);
            }else{
                while (!st.empty() && height[i] > height[st.top()])
                {
                    /* code */
                    int mid = st.top();
                    st.pop();
                    if(!st.empty()){
                        int h = min(height[i], height[st.top()]) - height[mid];
                        int w = i - st.top() - 1;
                        sum += h*w;
                    }
                }
                
            }
            st.push(i);
        }
        return sum;
    }
};