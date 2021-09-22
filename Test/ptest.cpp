#include<iostream>

using namespace std;

struct LNode{
    int val;
    LNode *next;
    LNode() : val(0), next(nullptr){};
};

int main(){
    LNode l1, l2;
    LNode *p1 = new LNode();
    *p1 = l1;
    LNode *p2 = &l2;
    cout<<p1->val<<" "<<l1.val;
    delete p1;
    cout<<l1.val;

}