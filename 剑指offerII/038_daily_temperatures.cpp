#include<iostream>
#include<stack>
#include<vector>

using namespace std;
/* 
请根据每日 气温 列表 temperatures ，重新生成一个列表，要求其对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

//单调栈，重点在于栈里面要存储温度对应的下标，而不是存储温度
 */
class Solution{
public:
    vector<int> dailyTemperatures2(vector<int>& temperatures){
        vector<int> res (temperatures.size(), 0);
        stack<int> st;

        for(int i = 0; i < temperatures.size(); ++i){
            if(st.empty()){
                st.push(temperatures[i]);
            }else{
                if(temperatures[i] < st.top() || temperatures[i] == st.top()){
                    st.push(temperatures[i]);
                }else{
                    int day = 1;
                    while(!st.empty() && temperatures[i] > st.top()){
                        res[i-day] = day++;
                    }
                    st.push(temperatures[i]);
                }
            }
            
        }

        return res;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures){
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;

        for(int i = 0; i < temperatures.size(); ++i){
            if(st.empty()){
                st.push(i);
            }else{
                if(temperatures[i] < temperatures[st.top()] || temperatures[i] == temperatures[st.top()]){//当前遍历元素的温度小于等于栈顶元素温度，满足单调递减栈，入栈
                    st.push(i);
                }else{//当前遍历元素大于栈顶元素，不满足单调递减栈，
                    int temp = i;
                    while (!st.empty() && temperatures[i] > temperatures[st.top()])
                    {
                        ans[st.top()] = i - st.top();
                        st.pop();
                    }
                    st.push(i);
                }
            }
            //优化
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        // while(!st.empty()){
        //     ans[st.top()] == 0;
        //     st.pop();
        // }
        return ans;
    }
};