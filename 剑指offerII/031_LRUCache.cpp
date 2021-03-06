/* 
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

思路：get和put操作使用哈希表都可以在O(1)的时间复杂度内完成，哈希表来存储 key - node
再使用一个双向链表来反映关键字的最新使用情况，最近使用的放在链表头部，即每次get操作后将其移入双向链表的头部，
put操作时，如果key不存在，插入，并根据容量大小来决定是否删除尾部节点。如果存在，修改value。

详细的操作：
get 不存在key值时返回-1；存在key时返回value,并且将该节点移至双向链表的头部表示最近刚使用过。move 操作
    移动节点到头部，分为两步，第一步删除原先的节点，第二步，在头结点后面插入该节点  move 包括 tohead he delete操作

put 存在key时，修改value, 将该键值对节点移至链表头部表示最近访问过      move 操作
    不存在时，插入双向链表，如果链表的长度超过容量则删除最后一个节点，将key-node存储在哈希表中 delete操作

tips: 在双向链表的实现中，使用一个伪头部（dummy head）和伪尾部（dummy tail）标记界限，这样在添加节点和删除节点的时候就不需要检查相邻的节点是否存在。

!!! 为了练习 LinkedHashMap ,双向链表加哈希表组成的数据结构，其中双向链表中存储key-value键值对而不是单纯存储value是为了在容量达到要求删除尾部节点前节点时可以通过节点中的key来释放hashmap中的元素，
不然会导致hashmap中没有erase该元素。
hashmap中存储双向链表节点指针是为了可以根据key值直接找到链表中的位置，可以直接进行移动和删除操作


 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct DlinkNode
{
    int key, value;
    DlinkNode *prev;
    DlinkNode *next;
    DlinkNode():key(0), value(0), prev(nullptr), next(nullptr){}
    DlinkNode(int key, int value):key(key), value(value), prev(nullptr), next(nullptr){}
};

class LRUCache
{
private:
    unordered_map<int, DlinkNode*> mp;
    DlinkNode *head;
    DlinkNode *tail;
    int size;
    int capacity;
public:
    LRUCache(int capacity);
    ~LRUCache();

    int get(int key){
        if(mp.count(key) == 0){//不存在key
            return -1;
        }
        DlinkNode *temp = mp[key];
        moveToHead(temp);
        return temp->value;
    }

    void put(int key, int value){
        if(mp.count(key) == 0){
            DlinkNode *temp = new DlinkNode(key, value);
            addToHead(temp);
            ++size;
            mp[key] = temp;
            if(size > capacity){
                DlinkNode *tail_prev = tail->prev;
                removeNode(tail->prev);
                mp.erase(tail_prev->key);
                delete tail_prev;
                --size;
            }
        }else{
            DlinkNode *temp = mp[key];
            temp->value = value;
            moveToHead(temp);
        }
    }

    void removeNode(DlinkNode *node){//删除节点node
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DlinkNode *node){//在头部添加节点node
        node->next = head->next;
        head->next->prev = node;

        head->next = node;
        node->prev = head;
    }

    void moveToHead(DlinkNode *node){
        removeNode(node);
        addToHead(node);
    }
    // void removeTail(DlinkNode *node){
    //     DlinkNode *temp = node;
    //     removeNode()
    // }
};

LRUCache::LRUCache(int capacity) : capacity(capacity), size(0)
{
    head = new DlinkNode();
    tail = new DlinkNode();
    head->next = tail;
    tail->prev = tail;
}

LRUCache::~LRUCache()
{
}

int main(){
    LRUCache *lrc = new LRUCache(2);
    lrc->put(1, 1);
    lrc->put(2, 2);
    int param1 = lrc->get(1);
}

/* 
LRU 要求使用O(1)的时间复杂度，那么需要使用哈希表来完成get和put操作，但是哈希表是无序的，无法表示先后使用顺序，
因此这里考察的是哈希链表， 双向链表加哈希表组成的数据结构，将key - node存储在哈希表中，在双向链表中根据node的先后顺序来表示使用的先后顺序，最近使用放在双向链表的头部
双向链表中存储key-value值，为了当超过capacity时，使用双向链表中查找到的key来删除哈希表中的节点

get:
    if mp.count(key) != 0 return node->val;
    else return -1
put:
    if mp.count(key) != 0{//节点已存在，修改对应的值，并将其移至链表首位
        mp[key]->val = value;//修改值

        mp[key]->pre->next = mp[key]->next;//将node从双向链表取出
        mp[key]->next->pre = mp[key]->pre

        mp[key]->next = head->next;//将node插入双向链表首位
        head->next->pre = mp[key];
        mp[key]->pre = head;
        head->next = mp[key];
    }else{//不存在则插入哈希表以及双向链表中，如果插入后长度超过capacity则删除链表最后的元素
        ListNode* node = new ListNode(value);

        mp[key] = node;

        node->next = head->next;
        head->next->pre = node;
        node->pre = head;
        head->next = node;
    }
 */
// struct DLinkNode
// {
//    int key, value;
//    DLinkNode *pre, *next;
//    DLinkNode():key(0), value(0),pre(nullptr), next(nullptr){}
//    DLinkNode(int key, int value):key(key), value(value), pre(nullptr), next(nullptr){}
// //    DLinkNode(int key, int value):key(key), value(value), pre(nullptr), next(nullptr){}
// };
class LRUCache2{
private:
    unordered_map<int, DlinkNode*> mp;
    DlinkNode* head;
    DlinkNode* tail;
    int capacity;//容量
    int size;

public:
    LRUCache2(int capacity) : capacity(capacity), size(0){
        head = new DlinkNode();
        tail = new DlinkNode();
        head->next = tail;
        tail->prev = head;
    };
    ~LRUCache2(){};

    int get(int key){
        if(mp.count(key) != 0){//key存在,返回值，
            //将其移至双向链表首部(将节点移至链表首位，删除原本的节点)
            DlinkNode *temp = mp[key];
            move_to_head(temp);
            return temp->value;
            
        }else{//不存在，返回-1
            return -1;
        }
    }
    void put(int key, int value){
        if(mp.count(key) == 0){//key 不存在，直接插入
            DlinkNode *node = new DlinkNode(key, value);
            add_to_head(node);
            mp[key] = node;
            size++;
            if(size > capacity){//超出容量，删除尾结点前的节点，要记得删除mp中对应的元素
                DlinkNode *tail_prev = tail->prev;
                delete_node(tail->prev);
                mp.erase(tail_prev->key);
                delete tail_prev;
                --size;
            }
        }else{
            DlinkNode *temp = mp[key];
            temp->value = value;
            move_to_head(temp);
        }
    }

    void add_to_head(DlinkNode *node){
        node->next = head->next;
        head->next->prev = node;

        head->next = node;
        node->prev = head;
    }

    void delete_node(DlinkNode *node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void move_to_head(DlinkNode *node){
        delete_node(node);
        add_to_head(node);
    }
};
