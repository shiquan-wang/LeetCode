#include<iostream>
#include<string>
#include<vector>
using namespace std;

/* 
设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 互不相同 。 如果给出一个单词，请判定能否只将这个单词中一个字母换成另一个字母，使得所形成的新单词存在于你构建的字典中。
实现 MagicDictionary 类：

    MagicDictionary() 初始化对象
    void buildDict(String[] dictionary) 使用字符串数组 dictionary 设定该数据结构，dictionary 中的字符串互不相同
    bool search(String searchWord) 给定一个字符串 searchWord ，判定能否只将字符串中 一个 字母换成另一个字母，使得所形成的新字符串能够与字典中的任一字符串匹配。如果可以，返回 true ；否则，返回 false 。
思路：前缀树，在查找过程中标记是否是第一次遇到不同节点即可
 */
class Trie{//前缀树，
private:
   
public:
    bool isEnd;//判断是否是一个词的结尾
    vector<Trie*> children;//孩子节点
    Trie(): isEnd(false), children(26, nullptr){}

    void insert(const string& word){//将单词word插入前缀树
        Trie* node = this;
        for(auto ch : word){
            if(node->children[ch - 'a'] == nullptr){
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
    }
};
class MagicDictionary{
private:
    Trie* root;
    // i是word当前遍历到的位置
    bool dfs(Trie* root, string& word, int i, int edit){
        if(root == nullptr) return false;//找到叶子节点都没有替换成功

        if(root->isEnd && i == word.size() && edit == 1){//如果刚到字符串末尾并且node正好处于根节点并且只修改了一个字符
            return true;
        }

        if(i < word.size() && edit <=1){
            bool found = false;
            //遍历当前节点的所有子节点
            for(int j = 0; j < 26 && !found; ++j){
                //如果子节点存在，edit不改变，否则edit+1;
                int next = (j == word[i] - 'a') ? edit : edit + 1;
                found = dfs(root->children[j], word, i + 1, next);
            }
            return found;
        }
        return false;
    }
public:
    MagicDictionary(){
        root = new Trie();
    }

    void buildDict(vector<string> dictionary){//构建前缀树
        for(auto word : dictionary){
            root->insert(word);
        }
    }

    bool search(string searchWord){
        return dfs(root, searchWord, 0, 0);
    }
};