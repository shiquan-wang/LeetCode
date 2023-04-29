#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution{
public:
    int findKlargest(vector<int>& nums, int k){
        priority_queue<int, vector<int>, greater<int>> pq;//使用优先队列实现，优先队列内部结构是堆，
        for(int item : nums){
            pq.push(item);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};

class Solution1{
public:
    void heapSort(vector<int>& nums){
        int len = (int)nums.size() - 1;
        buildMaxHeap(nums, len);
        for(int i = len; i >= 1; --i){
            swap(nums[i], nums[0]);
            len -= 1;
            maxHeapify(nums, 0, len);//调整大根堆
        }
    }

    void buildMaxHeap(vector<int>& nums, int len){
        for(int i = len/2; i >= 0; --i){
            maxHeapify(nums, i, len);//从下往上逐个检查非叶子节点是否满足大根堆要求，
            //nums数组节点总数为nums.size,下标到len = nums.size() - 1, 最下边的非叶子节点下标为 len / 2
        }
    }

    void maxHeapify(vector<int>& nums, int i, int len){
        for(; i * 2 + 1 <= len;){
            int lson = i*2+1;//左孩子节点下标
            int rson = i*2+2;//右孩子节点下标
            int large;//较大值下标
            if(lson <= len && nums[lson] > nums[i]){
                large = lson;
            }else{
                large = i;
            }
            if(rson <= len && nums[rson] > nums[large]){
                large = rson;
            }
            if(large != i){//i节点值小于左右节点其中的一个，交换两者的值，依次向下判断交换后的节点是否符合大根堆
                swap(nums[i], nums[large]);
                i = large;
            }else{//节点i及其左右孩子节点符合大根堆要求
                break;
            }
        }
    }
    
    vector<int> sortArray(vector<int>& nums){
        heapSort(nums);
        return nums;
    }
};

class Solution2{
public:
    int findKthLargest(vector<int>& nums, int k){
        quicksort_findK(nums, k, 0, nums.size() - 1);
        return nums[nums.size()-k-1];
    }

    void quicksort_findK(vector<int>& nums, int k, int left, int right){
        if(left > right) return;

        int partition = nums[left];
        int l = left, r = right;
        while (l < r)
        {
            /* code */
            while (l < r && nums[l] < partition)
            {
                ++l;
            }
            while (l < r && nums[r] > partition )
            {
                --r;
            }
            if(l < r){
                swap(nums[l], nums[r]);
            }
        }
        if(l == k-1){
            return ;
        }else if(l < k-1){
            quicksort_findK(nums, k, l+1, right);
        }else{
            quicksort_findK(nums, k, 0, l-1);
        }
    }
};

int main(){
    Solution2 s1;
    vector<int> nums = {4, 6, 8, 5, 9};
    // vector<int> nums1 = s1.sortArray(nums);
    int k = 2;
    cout<<s1.findKlargest(nums, k);
    // for(int item : nums1){
    //     cout<<item<<" ";
    // }
}