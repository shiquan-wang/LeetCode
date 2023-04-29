// 子串压缩
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *mid;
    Node *right;
    Node():val(0), left(nullptr), mid(nullptr), right(nullptr){}
    Node(int val):val(val), left(nullptr), mid(nullptr), right(nullptr){}
    Node(int val, Node *left, Node *mid, Node *right):val(val), left(left), mid(mid), right(right){}
};


class Solution{
public:
    int res = INT_MIN;
    int dfs(Node* root){
        if(root == nullptr){
            return 0;
        }
        if(root->val == -1){
            return 0;
        }
        int left_sum = max(0, dfs(root->left));
        int mid_sum = max(0,dfs(root->mid));
        int right_sum = max(0, dfs(root->right));
        int price = max(left_sum + mid_sum, max(mid_sum + right_sum, right_sum + left_sum)) + root->val;//修改
        res = max(res, price);

        return max(left_sum, max(mid_sum, right_sum)) + root->val;//返回值修改
    }
    void get_maxvalue(vector<int>& nums){
        int n = nums.size();
        Node *root = new Node(nums[0]);
        Node *cur, *pre;

        queue<Node*> qu;
        qu.push(root);
        int index = 1;
        while (!qu.empty() && index < n)
        {
            /* code */
            cur = qu.front();
            qu.pop();

            cur->left = new Node(nums[index++]);
            if(cur->left->val != -1) qu.push(cur->left);
            cur->mid = new Node(nums[index++]);
            if(cur->mid->val != -1) qu.push(cur->mid);
            cur->right = new Node(nums[index++]);
            if(cur->right->val != -1) qu.push(cur->right);
        }

        int temp = dfs(root);//修改
        cout<<res;
    }
};

int main(){
    int n;
    vector<int> nums;
    cin>>n;
    int item;
    for(int i = 0; i < n; ++i){
        cin>>item;
        nums.push_back(item);
    }
    Solution s1;
    s1.get_maxvalue(nums);
}