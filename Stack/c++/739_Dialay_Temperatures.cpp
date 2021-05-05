#include <iostream>
#include <stack>
#include <vector>

using namespace std;
/* 暴力循环：第i个元素的结果遍历从i+1位置开始，一直到第一个比i元素高的值处结束，两者之间的距离存入ans[]中   timeout!!!!!!!
单调栈：
 */
class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    /* vector<int> dailyTemperatures(vector<int> T){     //暴力双层循环
        int n = T.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(T[i] >= T[j]){
                    continue;
                }else{
                    ans[i] = j-i;
                    break;
                }
            }
        }
        return ans;
    } */
    /* vector<int> dailyTemperatures(vector<int> T){      //递减栈
        int n = T.size();
        stack<int> s;
        vector<int> ans(n);
        for(int i = 0;i < n; i++){
            if(s.empty()){
                s.push(i);
            }
            if(T[i] <= T[s.top()]){
                s.push(i);
            }else{
                while(!s.empty() && T[i] > T[s.top()]){   //比T[i]小的值都出栈
                    int temp = s.top();
                    s.pop();
                    ans[temp] = i - temp;
                }
                s.push(i);                               //T[i]入栈
            }
        }
        return ans;
    } */

    //整理后的简洁写法
    vector<int> dailyTemperatures(vector<int>& T){      //递减栈
        int n = T.size();
        stack<int> s;
        vector<int> ans(n);
        for(int i = 0;i < n; i++){
            while(!s.empty() && T[i] > T[s.top()]){   //比T[i]小的值都出栈
                int temp = s.top();
                s.pop();
                ans[temp] = i - temp;
            }
            s.push(i);                               //T[i]入栈
        }
        return ans;
    }

};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

int main(){
    Solution s;
    vector<int> t ;
    t.push_back(73);
    t.push_back(74);
    t.push_back(75);
    t.push_back(71);
    t.push_back(69);
    t.push_back(72);
    t.push_back(76);
    t.push_back(73);
    vector<int>a(s.dailyTemperatures(t));
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
}
