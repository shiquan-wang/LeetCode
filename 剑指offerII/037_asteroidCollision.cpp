#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
/* 
给定一个整数数组 asteroids，表示在同一行的小行星。

对于数组中的每一个元素，其绝对值表示小行星的大小，正负表示小行星的移动方向（正表示向右移动，负表示向左移动）。每一颗小行星以相同的速度移动。

找出碰撞后剩下的所有小行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。
输入：asteroids = [5,10,-5]
输出：[5,10]
解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞

思路： 使用栈来存储数据，当前遍历元素和栈顶元素方向相同，入栈，否则比较两者质量大小，如果新元素质量大，出栈顶元素，继续比较新的元素和栈顶元素质量大小直到新的元素质量小于栈顶元素或者两者方向相同。
 */
class Solution{
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        stack<int> st;
         for(auto iter : asteroids){
            if(st.empty()){
                st.push(iter);
            }else{
                int temp = st.top();
                if(compare_sign(temp, iter)){//iter 和 栈顶元素比较符号, 符号相同，元素入栈
                    st.push(iter);
                }else{//iter和栈顶元素top符号不同，
                    if(abs(iter) < abs(temp)){//iter质量小于栈顶元素质量，iter被撞击爆炸
                        continue;
                    }else if(abs(iter) == abs(temp)){//iter 质量 和栈顶元素质量相同，两者都爆炸
                        st.pop();
                        continue;
                    }else{//iter质量大于栈顶元素质量，栈顶元素爆炸
                     while (!st.empty() && abs(iter) > abs(st.top()) && !compare_sign(st.top(), iter))//栈顶元素一直小于iter且两者异号则栈顶元素被撞击爆炸
                     {
                        st.pop();
                     }

                     if(st.empty()){//栈内元素都因为爆炸移除了
                        st.push(iter);
                     }else{
                        if(compare_sign(st.top(), iter)){//将爆炸的元素移除后，栈顶元素和iter符号相同，则iter入栈
                            st.push(iter);
                        }else if(abs(iter) == abs(st.top())){//会爆炸的元素移除后，若iter和栈顶元素异号，iter只能小于或等于栈顶元素的质量，如果相等两者都爆炸
                            st.pop();
                        }
                        //会爆炸的元素移除后，若iter质量小于栈顶元素的质量，不做处理即可
                     }
                } 
            }
            }  
        }
        vector<int> res(st.size(), 0);
        int n = res.size();
        while (!st.empty())
        {
            res[n-- - 1] = st.top();
            st.pop();
        }
        return res;
        
    }
   bool compare_sign(int a, int b){
       //return !((a^b) < 0);      //判断a 和 b是否异号, a和b符号相反是异或操作使得a^b符号位为1,小于0, 即若a和b异号，则a^b小于0，(a^b) < 0 为true, 加上！返回的就是0
        //后面发现例子[-2, -1, 1, 2]不能只判断异号，而是只用判断是否是前一个向右（大于0）后一个向左（小于0）即可，当两者向相反方向移动时返回false
        if(a > 0 && b < 0){
            return false;
        }else{
            return true;
        }
    }
};

int main(){
    Solution s1;
    vector<int> vec = {5, 10, -5};
    vector<int> ans = s1.asteroidCollision(vec);
    for(int iter : ans){
        cout<<iter<<" ";
    }
}