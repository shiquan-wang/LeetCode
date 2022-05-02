#include<iostream>
#include<vector>
#include<string>

using namespace std;

/* 
单词数组 words 的 有效编码 由任意助记字符串 s 和下标数组 indices 组成，且满足：
    words.length == indices.length
    助记字符串 s 以 '#' 字符结尾
    对于每个下标 indices[i] ，s 的一个从 indices[i] 开始、到下一个 '#' 字符结束（但不包括 '#'）的 子字符串 恰好与 words[i] 相等
给定一个单词数组 words ，返回成功对 words 进行编码的最小助记字符串 s 的长度 。

思路：将字符串反序插入字典树中，那么作为后缀的单词将不是叶子节点，比如"time" and "me", 反序插入"emit" and "em"，可以得知，time作为叶子节点，me不是叶子节点，在最终的 s中将被省略
最后字典树的叶子节点就代表了没有后缀的单词。统计叶子节点长度加一（#）的和就是我们要返回的长度
 */
class TrieNode{
private:

public:
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode(): isEnd(false), children(26, nullptr){}

    void insert(const string& word){//向字典树中插入新的单词
        TrieNode* node = this;
        for(auto ch : word){
            if(node->children[ch - 'a'] == nullptr){
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
    }
};

class Solution{
private:

public:
    // string reverse_str(string str){
    //     return reverse(str.begin(), str.end());
    // }
    void dfs(TrieNode* root, int leafLen, int& totalLen){//深度遍历字典树，统计每个叶子节点的长度
        bool isleaf = true;
        for(auto child : root->children){
            if(child != nullptr){
                isleaf = false;
                dfs(child, leafLen + 1, totalLen);
            }
        }
        if(isleaf) totalLen += leafLen;
    }
    int minimumLengthEncoding(vector<string>& words){
        TrieNode* root = new TrieNode();

        for(string str : words){//反转words中的单词并插入字典树
            reverse(str.begin(), str.end());
            root->insert(str);
        }

        int totalLen = 0;
        dfs(root, 1, totalLen);

        return totalLen;
    }
};