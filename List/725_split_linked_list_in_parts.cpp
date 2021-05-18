#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(){}
    ListNode(int x) : val(x){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    vector<ListNode*> splitListToParts(ListNode *root, int k){
        //计算链表长度
        ListNode *s = root;
        int size = 0;
        while(s){
            ++size;
            s = s->next;
        }
        //计算平均节点数以及余数（有几个链表节点+1）
        int avg = size / k;
        int mod = size % k;
        //分割链表
        ListNode *curr = root;
        ListNode *prev = nullptr;

        vector<ListNode *> l;

        for(int i = 0; i<k; ++i){ 
            ListNode *h = curr;
            int len = avg + ((i<mod)? 1 : 0); 
            for(int j = 0; j<len-1; ++j){ //这里长度要减一，因为本身curr就已经是1了
                if(curr != nullptr){
                    curr = curr->next;
                }
            }

            l.push_back(h);
            
            if(h != nullptr) cout<<h->val<<endl;
            
            if(curr != nullptr){//将curr->next置null
                prev = curr;
                curr = prev->next;
                prev->next = nullptr;
            }  
        }
        return l;
    }
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    ListNode *root = new ListNode(1);
    ListNode *tail = root;
    for(int i = 1;i<7;++i){
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = tail->next;
    }
    Solution s;
    vector<ListNode *> res = s.splitListToParts(root, 3);
}