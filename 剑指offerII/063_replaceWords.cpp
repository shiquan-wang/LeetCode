#include<iostream>
#include<string>
#include<vector>
#include"062_Trie.cpp"
using namespace std;
/* 
在英语中，有一个叫做 词根(root) 的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。
现在，给定一个由许多词根组成的词典和一个句子，需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。
需要输出替换之后的句子。

输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
输出："the cat was rat by the bat"

 */
class Solution{
private:
    struct TrieNode
    {
        bool isEnd;
        vector<TrieNode*> children;
        TrieNode() : isEnd(false), children(26, nullptr){}
    };
    TrieNode* root = new TrieNode();
public:
    void buildTrie(vector<string>& dictionary){//根据dictionary 构建前缀树
        for(string word : dictionary){
            auto node = root;
            for(char& ch : word){
                if(node->children[ch - 'a'] == nullptr){
                    node->children[ch - 'a'] = new TrieNode();
                }
                node = node->children[ch - 'a'];
            }
            node->isEnd = true;
        }
    }

    string findPrefix(const string& word){//寻找字符串word在前缀树中的前缀
        auto node = root;
        string res = "";
        for(auto ch : word){
            if(node->isEnd || node->children[ch - 'a'] == nullptr) break;//寻找到一个前缀或者遍历完word后还没有找到符合的前缀

            res += ch;
            node = node->children[ch - 'a'];
        }
        return node->isEnd ? res : "";//有前缀返回前缀，没有返回空字符串
    }

    string replaceWords(vector<string>& dictionary, string sentence){
        buildTrie(dictionary);
        string res = "", str = "";

        for(char& ch : sentence){
            if(ch != ' '){
                str += ch;
            }else{
                string prefix = findPrefix(str);
                if(!prefix.empty()) res += prefix + " ";//寻找到了就追加前缀
                else res += str + " ";//找不到前缀追加原单词
                str = "";//重置str
            }
        }

        res += findPrefix(str) == "" ? str : findPrefix(str);//添加最后一个单词

        return res;
    }
};