#include<iostream>
#include<vector>

using namespace std;
/* 
基数排序是按照低位先排序，然后收集；再按照高位排序，然后再收集；依次类推，直到最高位。
有时候有些属性是有优先级顺序的，先按低优先级排序，再按高优先级排序。最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前 
算法描述
1,取得数组中的最大数，并取得位数；
2,arr为原始数组，从最低位开始取每个位组成radix数组；
3,对radix进行计数排序（利用计数排序适用于小范围数的特点）
*/

class Solution{
public:
    vector<int> Radix_sort(vector<int>& nums){
        int n = nums.size();
        if(n <= 1) return nums;
        int min = INT_MAX, max = INT_MIN;
        for(int i : nums){//寻找数组的最大值，确定最多的位数
            if(i < min) min = i;
            if(i > max) max = i;
        }

        max = max > (-min) ? max : -min;//考虑负数可能会影响最多的位数，例如45， -321;
        
        int dight = 0;
        while (max > 0)
        {
            max /= 10;
            ++dight;
        }

        //vector<vector<int>> bucket(19);
        int flag = 1;
        vector<int> ans;
        for(int i=0; i < dight; ++i){
            vector<int> bucket(19, 0);

            for(int j = 0; j < n; ++j){
                int temp = nums[j]/flag%10 + 9;
                bucket[temp]++;
            }

            for(int j = 1; j < 19; ++j){
                bucket[j] += bucket[j-1];
            }

            for(int j = n-1; j >= 0; j--){
                int temp = nums[j]/flag%10+9;
                ans[--bucket[temp]] = nums[j];
            }
            nums.swap(ans);
            flag *= 10;
        }

        return nums;
    }
    vector<int> Radix_sort2(vector<int>& nums){
        int n=nums.size();
        int max=abs(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(max<abs(nums[i]))
                max=abs(nums[i]);
        }
        int w=0;
        while(max>0)
        {
            max/=10;
            w++;
        }
        int flag=1;
        vector<int> ans(n);
        for(int i=0;i<w;i++)
        {
            vector<int> bucket(19,0);
            for(int j=0;j<n;j++)
            {
                int temp=nums[j]/flag%10+9;
                bucket[temp]++;
            }
            for(int j=1;j<19;j++)
                bucket[j]+=bucket[j-1];
            for(int j=n-1;j>=0;j--)
            {
                int temp=nums[j]/flag%10+9;
                ans[--bucket[temp]]=nums[j];
            }
            nums.swap(ans);
            flag*=10;
        }
        return nums;
    }
    vector<int> Radix_sort3(vector<int>& nums){
        int n = nums.size();
        int maxData = abs(nums[0]);
        for(int i : nums){//求得nums绝对值最大的数值，方便求最大位数
            if(abs(i) > maxData) maxData = abs(i);
        }
        int d = 1, p = 10;
        while (maxData >= p)//最大位数
        {
            maxData /= 10;
            d++;
        }

        int flag = 1;
        vector<int> ans(nums.size());
        for(int i = 0; i < d; ++i){//d次排序
            vector<int> bucket(19, 0);
            for(int j = 0; j < n; ++j){
                int temp = nums[j]/flag%10+9;
                bucket[temp]++;
            }
            for(int j=1; j < 19; ++j){
                bucket[j] += bucket[j-1];
            }
            
            for(int j=n-1;j>=0;j--)
            {
                int temp=nums[j]/flag%10+9;
                ans[--bucket[temp]]=nums[j];
            }
            nums.swap(ans);
            flag*=10;
        }
        
    }
};

int main(){
    vector<int> nums = {3, 2, 5, 4, 1, 67, 34};
    Solution s1;
    vector<int> res = s1.Radix_sort2(nums);
    for(int i : res){
        cout<<i<<"\t";
    }
}