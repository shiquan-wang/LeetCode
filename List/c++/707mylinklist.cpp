#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int val): val(val), next(nullptr){}
    ListNode(int val, ListNode* next): val(val), next(next){}
};

class MyLinkedList{
public:
    MyLinkedList(){

    }

    int get(int index){

    }

    void addAtHead(int val){

    }

    void addAtTail(int val){

    }

    void addAtIndex(int index, int val){

    }

    void deleteAtIndex(int index){

    }
};