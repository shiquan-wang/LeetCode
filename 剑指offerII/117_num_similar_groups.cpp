#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
/* 
如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，那么称 X 和 Y 两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。

例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)； "rats" 和 "arts" 也是相似的，但是 "star" 不与 "tars"，"rats"，或 "arts" 相似。

总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}。注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似。形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。

给定一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的一个 字母异位词 。请问 strs 中有多少个相似字符串组？

字母异位词（anagram），一种把某个字符串的字母的位置（顺序）加以改换所形成的新词。

 */
class UnionFind{
private:
    int num = 0;
    unordered_map<int, int> father;
public:
    // void add(int x){//添加元素
    //     if(father.count(x) == 0){
    //         father[x] = -1;
    //         num++;
    //     }
    // }
    void init(int n){//初始化，每个节点的根节点是本身
        for(int i = 0; i < n; ++i){
            father[i] = i;
            num++;
        }
    }
    int find(int x){
        int root = father[x];//初始化后每个节点的根节点时它本身，如果他的根节点不是本身，说明他的根节点往上还有节点
        while (father[root] != root)
        {
            root = father[root];
        }
        
        while (x != root)//压缩路径
        {
            int origin_father = father[x];
            father[x] = root;
            x = origin_father;
        }
        return root;
    }

    void merge(int a, int b){
        int root_a = find(a);
        int root_b = find(b);

        if(root_a != root_b){
            father[root_a] = root_b;
            num--;
        }
    }

    int get_num(){
        return num;
    }
};
class Solution{
public:
    bool is_anagram(string a, string b){//判断a b是否是字母异位词
        if(a.size() != b.size()) return false;
        int flag = 0;
        for(int i = 0; i < a.size(); ++i){
            if(a[i] != b[i]){
                flag++;
                if(flag > 2){//如果字符不同的位置多于两个则不是字母异位词
                    return false;
                }
            }
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs){
        UnionFind uf;
        // for(int i = 0; i < strs.size(); ++i){
            
        // }
        uf.init(strs.size());
        for(int i = 0; i < strs.size(); ++i){
            // uf.add(i);
            for(int j = i+1; j < strs.size(); ++j){
                if(is_anagram(strs[i], strs[j])){
                    uf.merge(i, j);
                }
            }
        }
        return uf.get_num();
    }
};


int main(){
    vector<string> strs = {"tars", "rats", "arts", "star"};
    Solution s1;
    cout<<s1.numSimilarGroups(strs);
    // unordered_map<int, int> mp;
    // int a = mp[1];
    // cout<<mp[1];
}