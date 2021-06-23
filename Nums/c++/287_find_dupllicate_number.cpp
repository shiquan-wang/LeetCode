/* 一个数组只有一个重复的数字出现，寻找到这个数并且不改变数组顺序且使用常数级别的额外空间 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    /* data */
public:
    //快慢指针，数组形式的链表 题目设定的问题是 N+1 个元素都在 [1,n] 这个范围内。这样我们可以用那个类似于 ‘缺失的第一个正数’ 这种解法来做，
    // 但是题意限制了我们不能修改原数组，我们只能另寻他法。也就是本编题解讲的方法，将这个题目给的特殊的数组当作一个链表来看，
    // 数组的下标就是指向元素的指针，把数组的元素也看作指针。如 0 是指针，指向 nums[0]，而 nums[0] 也是指针，指向 nums[nums[0]].
    //     int point = 0;
    //     while(true){
    //     point = nums[point]; // 等同于 next = next->next; 
    // }
//快慢指针
    // int findDuplicate(vector<int>& nums){
    //     int slow = 0, fast = 0;
    //     do{
    //         slow = nums[slow];
    //         fast = nums[nums[fast]];
    //     }while(slow != fast);
    //     slow = 0;
    //     while(slow != fast){
    //         slow = nums[slow];
    //         fast = nums[fast];
    //     }
    //     return slow;
    // }

    int findDuplicate(vector<int>& nums){ //二分查找
        int n = nums.size();
        int l = 1, r = n-1;
        int res=-1;
        while (l<=r)
        {
            int mid = (l+r)>>1;
            int count = 0;
            for(int i = 0; i<n; ++i){
                // if(nums[i] <= mid)   //计算比小于等于mid数的个数
                //     count++;
                count += nums[i]<=mid;
            }
            if(count <= mid){   //此时重复的数不在l到mid中
                l = mid + 1;
            }
            else{
                r = mid -1;
                res = mid;
            }
        }
        return res;
    }
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}
