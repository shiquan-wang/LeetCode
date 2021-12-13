#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        vector<int> res(nums1.size(), -1);
        stack<int> s;
        unordered_map<int, int> unmap;

//这一部分可以优化，简单写法
        //构建单调栈， unordered_map记录每一个元素右边第一个比它大的元素的值
        s.push(nums2[nums2.size() - 1]);//
        unmap[nums2[nums2.size() - 1]] = -1;//
        for(int i = nums2.size() - 2; i >= 0; --i){

            if(nums2[i] < s.top()){//当前遍历元素小于栈顶元素，符合单调递增栈，可以直接进栈； 此时栈顶元素即为右边第一个大于nums2[i]的元素
                unmap[nums2[i]] = s.top();//map 键值对， 键为nums2[i]数， 值为第一个比nums2[i]大的数
                s.push(nums2[i]);
            }else if(nums2[i] == s.top()){//本题中不存在相同元素，可以不考虑这一点
                s.push(nums2[i]);
            }else{
                while(!s.empty() && nums2[i] > s.top()){
                    s.pop();
                }
                unmap[nums2[i]] = s.empty() ? -1 : s.top();//将小于nums2[i]的元素全部出栈后，s.top()就是第一个大于nums2[i]的数了 重点！！！这里最开始写unmap[nums2[i]] = s.top()，这样写
                //会出现问题，当nums2[i]为最大值时，会将栈s清空，s为空时，s.top()赋值给unmap是0，而不是-1
                s.push(nums2[i]);
            }
        }
//到这里为止

        /* for(int i : nums2){
            cout<<unmap[i]<<"\t";
        } */
        for(int i = 0; i < nums1.size(); ++i){
            res[i] = unmap[nums1[i]];
        }

        return res;
    }
    vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2){
        vector<int> res(nums1.size(), -1);
        stack<int> s;
        unordered_map<int, int> unmap;
//简化后的单调栈构建方法，只有当前遍历元素大于栈顶元素时，才需要先进行出栈操作，其他情况都只有入栈一个操作，重点在于map值的确定与入栈操作的前后关系。
        for(int i = nums2.size() - 1; i >= 0; --i){
            while(!s.empty() && nums2[i] > s.top()){
                s.pop();
            }
            unmap[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); ++i){
            res[i] = unmap[nums1[i]];
        }
        return res;
    }
};

int main(){
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution s1;
    vector<int> res = s1.nextGreaterElement(nums1, nums2);
}