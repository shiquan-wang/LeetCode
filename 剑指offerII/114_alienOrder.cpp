/* 
现有一种使用英语字母的外星文语言，这门语言的字母顺序与英语顺序不同。
给定一个字符串列表 words ，作为这门语言的词典，words 中的字符串已经 按这门新语言的字母顺序进行了排序 。
请你根据该词典还原出此语言中已知的字母顺序，并 按字母递增顺序 排列。若不存在合法字母顺序，返回 "" 。若存在多种可能的合法字母顺序，返回其中 任意一种 顺序即可。
字符串 s 字典顺序小于 字符串 t 有两种情况：

在第一个不同字母处，如果 s 中的字母在这门外星语言的字母顺序中位于 t 中字母之前，那么 s 的字典顺序小于 t 。
如果前面 min(s.length, t.length) 字母都相同，那么 s.length < t.length 时，s 的字典顺序也小于 t 。

思路：
遍历words,构建有向图，然后遍历有向图寻找一条拓扑路径，如果出现环则非法返回" "
 */
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class  Solution{
private:
    unordered_map<char, vector<char>> edges;//邻接矩阵存储边
    unordered_map<char, int> states;//存储遍历过程中节点的状态，012三种状态代表未遍历 遍历中 已便利, 因为使用的是map，所有可以根据map中是否存在ch来判断ch是否遍历 深度优先搜索遍历图必须的辅助工具
    bool valid = true;//辅助变量，判断图中是否存在环
    string order;
    int index;
public:
    void addEdge(string word1, string word2){
        int length1 = word1.size(), length2 = word2.size();
        int length = min(length1, length2);
        int index = 0;
        while (index < length)
        {
            char c1 = word1[index], c2 = word2[index];
            if(c1 != c2){
                edges[c1].push_back(c2);
                break;
            }
            index++;
        }
        if(index == length && length1 > length2){//如果遍历到word1和word2较短者长度后，遇到的字符都一样，而且word1比word2长，那么不符合字典要求，valid置为false
            valid = false;
        }
    }

    void dfs(char u){
        states[u] = 1;
        for(char v : edges[u]){
            if(!states.count(v)){
                dfs(v);
                if(!valid){
                    return;
                }
            }else if(states[v] = 2){
                valid = false;
                return;
            }
        }
        states[u] = 2;
        order[index] = u;
        index--;
    }
    string alienOrder(vector<string>& words){
        int length = words.size();
        for(string& word : words){//将words中所有出现的字符放入邻接矩阵中，相当于初始化邻接矩阵。因为words中存在的字母可能不是26个字母都存在。
            int wordLength = word.size();
            for(int j = 0; j < wordLength; ++j){
                char ch = word[j];
                if(!edges.count(ch)){
                    edges[ch] = vector<char>();
                }
            }
        }

        for(int i = 1; i < length; ++i){//构造邻接矩阵
            addEdge(words[i-1], words[i]);
        }

        order = string(edges.size(), ' ');
        index = edges.size() - 1;
        for(auto [u, _] : edges){
            if(!states.count(u)){//u未遍历
                dfs(u);
            }
        }
        if(!valid){
            return "";
        }
        return order;
    }
};

int main(){
    
}