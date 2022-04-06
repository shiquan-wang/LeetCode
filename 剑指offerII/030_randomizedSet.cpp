/* 
设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构：

insert(val)：当元素 val 不存在时返回 true ，并向集合中插入该项，否则返回 false 。
remove(val)：当元素 val 存在时返回 true ，并从集合中移除该项，否则返回 false 。
getRandom：随机返回现有集合中的一项。每个元素应该有 相同的概率 被返回。

思路：unorder_set来辅助构建该容器
首先，insert和remove操作 哈希表可以达到O(1)的时间复杂度，但是getRandom操作因为哈希表没有索引，所以无法完成该操作。
动态数组vector,可以在O(1)时间复杂度完成insert和getRandom操作，但是无法完成remove操作

因此，结合vector和hashset 在vector中存储value，在hashset中存储value和其对应在vector中的下标

*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class RandomizedSet{
private:
    vector<int> vec;
    unordered_map<int, int> mp;//val : index
public:
    RandomizedSet(){
        vec.clear();
        mp.clear();
    }

    bool insert(int val){
        if(mp.count(val) == 1) return false;//val已经存在
        vec.push_back(val);
        int index = vec.size();
        mp[val] = index-1;
        return true;
    }

    bool remove(int val){
        if(mp.count(val) == 0) return false;//val不存在，无法移除
        //当val存在时，首先通过unorder_map获取到该元素的下标，然后将最后一个元素移到该下标处，修改该元素在map中的对应键值对，最后vec.pop_back()，移除最后一个元素。 ！！！mp.erase(val)也需要
        int index = mp[val];//获取下标
        vec[index] = vec[vec.size() - 1];//最后一个元素移至index处
        mp[vec[index]] = index;//修改map
        mp.erase(val);//!!之前忘记这一步了
        vec.pop_back();//删除元素
        return true;
        /* 
        最初：3， 4， 2， 6， 5， 1 删除 6
        过程：3， 4， 2， 1， 5， 1 ---》 3， 4， 2， 1， 5
        第一次错误原因，没有将mp中对应的应删除的元素键值对删除
         */
    }

    int getRandom(){
        int index = rand()%(vec.size());//rand() % length 返回的是 0 - (length-1)的任意值
        return vec[index];
    }
};

int mian(){
    RandomizedSet *obj = new RandomizedSet();
    bool param1 = obj->insert(1);
    bool param2 = obj->insert(2);
    bool param3 = obj->remove(2);
    bool param4 = obj->insert(2);
    int param5 = obj->getRandom();

}