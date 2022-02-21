#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

/* 
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a ，b ，c ，使得 a + b + c = 0 ？请找出所有和为 0 且 不重复 的三元组

首先类似于两数之和，但不同之处在于，本题数组无序且有重复元素，所以想要获取不重复的三元组，需要先排序，然后在遍历过程中遇到不同的元素才开始计算
双指针思路在于，当确定好第一个元素后，第二个和第三个元素的和是确定的，这个时候可以模仿两数之和的做法，头尾指针同时遍历，减少时间复杂度
如果我们固定了前两重循环枚举到的元素 a 和 b，那么只有唯一的 c 满足 a+b+c=0。当第二重循环往后枚举一个元素 b'时，由于 b' > b，
那么满足 a+b'+c'=a+b+c′=0 的 c'一定有 c' < c，即 c'在数组中一定出现在 c 的左侧。也就是说，我们可以从小到大枚举 b，同时从大到小枚举 c，即第二重循环和第三重循环实际上是并列的关系。
 */
class Solution{
public:
    vector<vector<int>> threeSum_me(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i-1]){//去除重复元素i
                continue;
            }
            
            int target = -nums[i];
            for(int j = i+1, k = n-1; j < n; ++j)
            {
                if(j > i+1 && nums[j] == nums[j-1]){//去重j
                    continue;
                }
                while (j < k && nums[k] + nums[j] > target)
                {
                    --k;
                }
                if(j == k){
                    break;
                }
                if(nums[j] + nums[k] == target){
                    res.push_back({i, j, k});
                }
            }
            
        }

        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }

};