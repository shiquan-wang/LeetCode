#include<iostream>
#include<vector>
#include<string>
#include<bitset>
using namespace std;

/* 
给定一个字符串数组 words，请计算当两个字符串 words[i] 和 words[j] 不包含相同字符时，
它们长度的乘积的最大值。假设字符串中只包含英语的小写字母。如果没有不包含相同字符的一对字符串，返回 0。

思路一：遍历words数组，两两比较， 两两比较的过程中需要遍历两个字符串O(L1 * L2),l1 l2是字符的长度, 
总的时间复杂度高于O（n^2)

 */
class Solution{
public:
    int maxProduct(vector<string>& words){
        int res = 0;
        for(int i = 0; i < words.size() - 1; ++i){//遍历words数组，两两比较是否包含相同字母， 
            for(int j = i+1; j < words.size(); ++j){//比较words[i] 和 words[j] 观察是否包含相同字母
                if( isdiff(words[i], words[j]) ){
                    int temp = words[i].size() * words[j].size();
                    if(temp > res){
                        res = temp;
                    }
                }
            }
        }
        return res;
    }

    bool isdiff(string s1, string s2){//比较words[i] 和words[j]是否包含相同字母，不包含返回true, 否则返回false
        for(int i = 0; i < s1.size(); ++i){
            for(int j = 0; j < s2.size(); ++j){
                if(s1[i] == s2[j]){
                    return false;
                }
            }
        }
        return true;
    
    }

    // bool ifdiff_bit(string s1, string s2){//使用位运算来判断s1与s2是否含有相同字母
    // //使用26位的2进制数字来表示一个字符串，0-25位表示a-z是否在该字符串中出现过，出现过为1，否则为0.
    // //s1 && s2 结果为0说明没有重复字母，否则有重复字母。
    //     int mask1 = 0;
    //     for(auto i : s1){
    //         mask1 |= 1<<(i - 'a');
    //     }

    // }
    int maxProduct2(vector<string>& words){
        /* 
        对于每一个字符串 word[i]，其是否包含 26 个英文字母，可以用一个32位二进制的数字表示，二进制位第[0,25]位，分别对应[a,z]每一位的状态为0或1，0表不存在该字母，1表示存在该字母，
        （存在多次在得到二进制的过程中使用的是或运算，不影响最终的表示）
        因此可以利用位运算O(1)的判断两个字符words[i]和words[j]是否有公共字母。
        时间复杂度：O(n^2)
        空间复杂度：O(n)
        tips：& 按位与 | 按位或 ^ 异或 ~取反
         */
        vector<int> masks(words.size());//mask数组用来存储每个字符串的二进制表示，初始全部为0
        //计算每一个字符串的二进制表示得到masks数组
        for(int i = 0; i < words.size(); ++i){
            for(int j = 0; j < words[i].size(); ++j){
                masks[i] = masks[i] | (1 << (words[i][j] - 'a'));//masks[i] 是第i个字符串的二进制表示，第j位的字母,将1左移其与'a'的差值的位数，例如c表示为00...100,    再与mask[i]进行或运算
                //cout<<masks[i]<<endl;
            }
        }
        for(auto i : masks){
            cout<<(bitset<32>)i<<endl;
        }
        //两两遍历words数组中的数值，判断是否含有重复字母
        int res = 0;
        for(int i = 0; i < words.size()-1; ++i){
            for(int j = i+1; j < words.size(); ++j){
                if((masks[i] & masks[j]) == 0){
                    int temp = words[i].size() * words[j].size();
                    if(temp > res){
                        res = temp;
                    }
                }
            }
        }

        return res;
    }
};

int main(){
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    Solution s1;
    cout<<s1.maxProduct2(words);
}