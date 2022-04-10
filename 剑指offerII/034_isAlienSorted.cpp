#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

/* 
某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。

思路：倒序遍历，依次比较每一位的顺序，使用哈希表存储字母表顺序，key = char， value = 顺序。使用减法确定是否按照字母表的顺序

string find函数可以找到字母在字符串中的位置
 */

class Solution{
private:
    bool compare(string& a, string& b, string& order){
        int len = min(a.size(), b.size());

        for(int i = 0; i < len; ++i){
            if(order.find(a[i]) < order.find(b[i])){
                return true;
            }else if(order.find(a[i] > order.find(b[i]))){
                return false;
            }
        }

        if(len == a.size()) return true;
        else return false;
        // return a.size() == len;

    }
public:
    bool isAlienSorted(vector<string>& words, string order){
        

        for(int i = 0, j = 1; j < words.size(); ++i, ++j){//依次两两字符串比较
            bool temp = compare(words[i], words[j], order);
            if(compare(words[i], words[j], order) == false) return false;
        }

        return true;
    }
};

int mian(){
    vector<string> words = {"hello", "hello"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    Solution s;
    cout<<s.isAlienSorted(words, order);

}