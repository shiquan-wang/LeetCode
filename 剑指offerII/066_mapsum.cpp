#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
/* 
实现一个 MapSum 类，支持两个方法，insert 和 sum：
    MapSum() 初始化 MapSum 对象
    void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。如果键 key 已经存在，那么原来的键值对将被替代成新的键值对。
    int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
思路一：使用哈希表来存储，其中一个哈希表存储key-value值，另一个用来存储每个key的前缀对应的值的和，计算如下
    如果键key不存在，此时key对应的前缀应该增加的值为val
    如果键key存在，此时key对应的前缀应该增加的值为val - map[key],因为要将原来的map[key]更换为val,所以key的所有前缀应该增加的值是两者的差
    更新完key对应的所有前缀值后，将key对应的key修改为val
思路二：字典树
 */
class MapSum{
private:
    unordered_map<string, int> mp;
    unordered_map<string, int> prefixmp;
public:
    MapSum(){}

    void insert(string key, int val){
        int delta = val;
        if(mp.count(key) == 1){
            delta -= mp[key];
        }
        for(int i = 1; i <= key.size(); ++i){
            prefixmp[key.substr(0, i)] += delta;
        }
        mp[key] = val;
    }

    int sum(string prefix){
        return prefixmp[prefix];
    }
};

class TrieNode{
private:

public:
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode():isEnd(false), children(26, nullptr){}

    void insert(const string& word){
        TrieNode* node = this;
        for(char ch : word){
            if(node->children[ch - 'a'] == nullptr){
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
    }
};

class MapSum{
private:
    TrieNode* root;
    unordered_map<string, int> cnt;
public:
    MapSum(){
        root = new TrieNode();
    }

    void insert(string key, int val){
        int delta = val;
        if(cnt.count(key) == 1){
            delta -= cnt[key];
        }
        cnt[key] = val;
        
    }

    int sum(string prefix){

    }
};