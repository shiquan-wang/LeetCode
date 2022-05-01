#include<iostream>
#include"TreeNode.h"
#include<string>
#include<vector>

using namespace std;
/* 
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。
请你实现 Trie 类：

    Trie() 初始化前缀树对象。
    void insert(String word) 向前缀树中插入字符串 word 。
    boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
    boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
思路：
前缀树又称为字典树，每个节点包含以下字段：
    指向子节点的指针数组 children。对于本题而言，数组长度为 26，即小写英文字母的数量。此时children[0] 对应小写字母 a，children[1] 对应小写字母 b，children[25] 对应小写字母 z
    布尔字段 \textit{isEnd}isEnd，表示该节点是否为字符串的结尾。
插入字符串：
我们从字典树的根开始，插入字符串。对于当前字符对应的子节点，有两种情况：

    子节点存在。沿着指针移动到子节点，继续处理下一个字符。
    子节点不存在。创建一个新的子节点，记录在 \textit{children}children 数组的对应位置上，然后沿着指针移动到子节点，继续搜索下一个字符。
重复以上步骤，直到处理字符串的最后一个字符，然后将当前节点标记为字符串的结尾。

查找前缀
我们从字典树的根开始，查找前缀。对于当前字符对应的子节点，有两种情况：

    子节点存在。沿着指针移动到子节点，继续搜索下一个字符。
    子节点不存在。说明字典树中不包含该前缀，返回空指针。
重复以上步骤，直到返回空指针或搜索完前缀的最后一个字符。
若搜索到了前缀的末尾，就说明字典树中存在该前缀。此外，若前缀末尾对应节点的 \textit{isEnd}isEnd 为真，则说明字典树中存在该字符串

https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/trie-tree-de-shi-xian-gua-he-chu-xue-zhe-by-huwt/
 */
// class Trie{
// private:
//     vector<Trie*> children;
//     bool isEnd;

//     Trie* searchPrefix(string prefix){
//         Trie* node = this;
//         for(char ch : prefix){
//             ch -= 'a';
//             if(node->children[ch] == nullptr){
//                 return nullptr;
//             }
//             node = node->children[ch];
//         }
//         return node;
//     }
// public:
//     Trie() : children(26), isEnd(false){
        
//     }
    

//     void insert(string word){
//         Trie* node = this;
//         for(char ch : word){
//             ch -= 'a';
//             if(node->children[ch] == nullptr){
//                 node->children[ch] = new Trie();
//             }
//             node = node->children[ch];
//         }
//         node->isEnd = true;
//     }

//     bool search(string word){
//         Trie* node = this->searchPrefix(word);
//         return node != nullptr && node->isEnd;
//     }

//     bool startsWith(string prefix){
//         return this->searchPrefix(prefix) != nullptr;
//     }

// };

class Trie{
private:
    bool isEnd;
    vector<Trie*> children;
public:
    Trie(){
        isEnd = false;
        children.resize(26);
    }
 /* 
插入
描述：向 Trie 中插入一个单词 word
实现：这个操作和构建链表很像。首先从根结点的子结点开始与 word 第一个字符进行匹配，一直匹配到前缀链上没有对应的字符，这时开始不断开辟新的结点，直到插入完 word 的最后一个字符，
同时还要将最后一个结点isEnd = true;，表示它是一个单词的末尾。
*/
    void insert(string word){
        Trie* node = this;
        for(auto ch : word){
            if(node->children[ch - 'a'] == nullptr){
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
    }
/* 
描述：查找 Trie 中是否存在单词 word

实现：从根结点的子结点开始，一直向下匹配即可，如果出现结点值为空就返回 false，如果匹配到了最后一个字符，那我们只需判断 node->isEnd即可
 */
    bool search(string word){
        Trie* node = this;
        for(auto ch : word){
            node = node->children[ch - 'a'];
            if(node == nullptr){//word中的字符还没有完全遍历完毕已经出现空节点了，那么word就没有在前缀树中存在
                return false;
            }
        }
        return node->isEnd;
    }
/* 
前缀匹配
描述：判断 Trie 中是或有以 prefix 为前缀的单词

实现：和 search 操作类似，只是不需要判断最后一个字符结点的isEnd，因为既然能匹配到最后一个字符，那后面一定有单词是以它为前缀的。
 */
    bool startsWith(string prefix){
        Trie* node = this;
        for(char ch : prefix){
            node = node->children[ch - 'a'];
            if(node == nullptr){
                return false;
            }
        }
        return true;
    }
};
/* 
通过以上介绍和代码实现我们可以总结出 Trie 的几点性质：

    Trie 的形状和单词的插入或删除顺序无关，也就是说对于任意给定的一组单词，Trie 的形状都是唯一的。

    查找或插入一个长度为 L 的单词，访问 next 数组的次数最多为 L+1，和 Trie 中包含多少个单词无关。

    Trie 的每个结点中都保留着一个字母表，这是很耗费空间的。如果 Trie 的高度为 n，字母表的大小为 m，最坏的情况是 Trie 中还不存在前缀相同的单词，那空间复杂度就为 O(m^n)。

最后，关于 Trie 的应用场景，希望你能记住 8 个字：一次建树，多次查询。(慢慢领悟叭~~)

 */