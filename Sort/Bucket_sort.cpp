#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 
桶排序是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。
桶排序 (Bucket sort)的工作的原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排）。
算法描述
1, 设置一个定量的数组当作空桶；
2, 遍历输入数据，并且把数据一个一个放到对应的桶里去；
3, 对每个不是空的桶进行排序；
4, 从不是空的桶里把排好序的数据拼接起来。
 */
class Solution{
public:
    vector<int> bucket_sort(vector<int>& nums){
        int n = nums.size();
        if(n <= 1) return nums;
        int min = INT_MAX, max = INT_MIN;
        for(int i = 0; i < n; ++i){
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
        }

        int bucket_num = (max - min) / n+1;//确定桶的个数
        vector<vector<int>> bucket(bucket_num);
        for(int i = 0; i < n; ++i){
            int num = (nums[i] - min) / n;
            bucket[num].push_back(nums[i]);
        }

        int count = 0;
        for(int i = 0; i < bucket_num; ++i){
            if(!bucket[i].empty()){
                sort(bucket[i].begin(), bucket[i].end());
                for(int j = 0; j < bucket[i].size(); ++j){
                    nums[count++] = bucket[i][j];
                }
            }
        }
        
        return nums;
    }
};

int main(){
    vector<int> nums = {3, 5, 4, 1, 2};
    Solution s1;
    vector<int> res = s1.bucket_sort(nums);
    for(int i : res){
        cout<<i<<"\t";
    }
}