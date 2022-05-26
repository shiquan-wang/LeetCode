/* 
在字典（单词列表） wordList 中，从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列：
序列中第一个单词是 beginWord 。
序列中最后一个单词是 endWord 。
每次转换只能改变一个字母。
转换过程中的中间单词必须是字典 wordList 中的单词。
给定两个长度相同但内容不同的单词 beginWord 和 endWord 和一个字典 wordList ，找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0。

 */
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;
/* 
思路：首先遍历wordlist，如果不存在endWord则直接返回0
本题要求的是最短转换序列的长度，看到最短首先想到的就是广度优先搜索。想到广度优先搜索自然而然的就能想到图，但是本题并没有直截了当的给出图的模型，因此我们需要把它抽象成图的模型。

我们可以把每个单词都抽象为一个点，如果两个单词可以只改变一个字母进行转换，那么说明他们之间有一条双向边。因此我们只需要把满足转换条件的点相连，就形成了一张图。
基于该图，我们以 beginWord 为图的起点，以 endWord 为终点进行广度优先搜索，寻找 beginWord 到 endWord 的最短路径。
首先为了方便表示，我们先给每一个单词标号，即给每个单词分配一个 id。创建一个由单词 word 到 id 对应的映射 wordId，并将 beginWord 与 wordList 中所有的单词都加入这个映射中。
之后我们检查 endWord 是否在该映射内，若不存在，则输入无解。我们可以使用哈希表实现上面的映射关系。
然后我们需要建图，依据朴素的思路，我们可以枚举每一对单词的组合，判断它们是否恰好相差一个字符，以判断这两个单词对应的节点是否能够相连。但是这样效率太低，我们可以优化建图。
具体地，我们可以创建虚拟节点。对于单词 hit，我们创建三个虚拟节点 *it、h*t、hi*，并让 hit 向这三个虚拟节点分别连一条边即可。如果一个单词能够转化为 hit，那么该单词必然会连接到这三个虚拟节点之一。对于每一个单词，
我们枚举它连接到的虚拟节点，把该单词对应的 id 与这些虚拟节点对应的 id 相连即可。
最后我们将起点加入队列开始广度优先搜索，当搜索到终点时，我们就找到了最短路径的长度。注意因为添加了虚拟节点，所以我们得到的距离为实际最短路径长度的两倍。同时我们并未计算起点对答案的贡献，所以我们应当返回距离的一半再加一的结果。

 */
class Solution{
public:
//广度优先搜索，
    unordered_map<string, int> word_id;
    vector<vector<int>> edge;
    int nodeNum = 0;
    void add_word(string& word){
        if(!word_id.count(word)){//如果word还没有作为节点加入map映射中
            word_id[word] = nodeNum++;
            edge.emplace_back();
        }
    }

    void add_edge(string& word){
        add_word(word);
        int id1 = word_id[word];
        for(char& it : word){//对于每一个单词，将其和虚拟节点相连接，（即用*逐个替代每个字符）
            char temp = it;
            it = '*';
            add_word(word);
            int id2 = word_id[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = temp;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        for(auto& str : wordList){
            add_edge(str);
        }

        add_edge(beginWord);
        if(!word_id.count(endWord)){
            return 0;
        }

        vector<int> dis(nodeNum, INT_MAX);
        int begin_id = word_id[beginWord], end_id = word_id[endWord];
        dis[begin_id] = 0;

        queue<int> que;
        que.push(begin_id);
        while (!que.empty())
        {
            int x = que.front();
            que.pop();
            if(x == end_id){
                return dis[end_id] / 2 + 1;
            }
            for(int it : edge[x]){
                if(dis[it] == INT_MAX){
                    dis[it] = dis[x] + 1;
                    que.push(it);
                }
            }
        }
        
        return 0;
    }
};