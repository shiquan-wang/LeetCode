#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution{
    ListNode *head;
public:
    Solution(ListNode* head){
        this->head = head;
    }

    int getRandom(){
        int i = 1, ans = 0;
        for(auto node = head; node; node = node->next){
            if(rand() % i == 0){
                ans = node->val;
            }
            ++i;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1, 2, 3};
}
