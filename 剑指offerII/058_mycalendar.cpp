#include<iostream>
#include<map>
using namespace std;
/* 
请实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内没有其他安排，则可以存储这个新的日程安排。

思路：暴力法，每次添加新的时间安排时，检测与之前的所有安排是否冲突
map :
    lower_bound(k)  表示找到map中键值大于等于K的元素
    upper_bound(k) 表示map中键值大于k的元素
unorder_set/map 底层是哈希表
set/map 底层是红黑树，二叉搜索树
map插入的方式： 
mp.insert(pair<int, int>(1, 10))   mp.insert(map<int, int>::value_type(1, 10))     mp[1] = 10

 */
class MyCalendar{
private:
    map<int, int> hash;
public:
    MyCalendar(){

    }

    bool book(int start, int end){
        map<int, int> :: iterator event = hash.lower_bound(start);
        //当前迭代器存在，并且迭代去左边界小于待插入日程的右边界
        if(event != hash.end() && event->first < end) return false;

        //上一迭代器存在，并且迭代器右边界大于待插入日程的左边界
        if(event != hash.begin() && (--event)->second > start) return false;

        hash[start] = end;

        return true;
    }
};