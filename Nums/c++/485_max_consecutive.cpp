#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    int findMaxConsecutiveOnes(vector<int>& nums){
        int num=0, max=0;
        for(int i=0; i<nums.size(); ++i){
            /* if(nums[i]==1){
                num++;
            }else{
                num = 0;
            }
            if(num>max){
                max = num;
            } */
            nums[i]==1 ? num++ : num=0;
            num > max ? max = num : max = max;
        }
        return max;
    }
};

Solution::Solution(/* args */)
{
}


Solution::~Solution()
{
}

int main(){
    vector<int> v(4);
    v[0]=0;v[1]=1;v[2]=1;v[3]=0;
    Solution s;
    cout<<s.findMaxConsecutiveOnes(v);
}
