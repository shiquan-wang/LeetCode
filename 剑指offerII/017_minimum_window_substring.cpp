#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

/* 
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 */
class Solution{
private:
    bool check(unordered_map<char, int> map1, unordered_map<char, int> map2){
        for(auto iter = map2.begin(); iter != map2.end(); ++iter){
            if(iter->second > map1[iter->first]){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t){
        int len_s = s.length(), len_t = t.length();
        if(s < t) return "";

        unordered_map<char, int> maps, mapt;
        string res = "";
        int res_start = -1;
        int len = INT_MAX;
        for(char ch : t){//记录字符串t中字符种类以及数量
            mapt[ch]++;
        }

        for(int left = 0, right = 0; right < len_s; ++right){//righ++ 步骤1,右移右边界，扩大窗口范围使得包含所有字符串t中所有元素
            maps[s[right]] ++;
            while(check(maps, mapt) && left <= right){//maps包含mapt中所有元素 !!!这里不能用if,要是用while,因为需要一直移动左边界，从而使得窗口变得最小
                if((right - left + 1) < len){
                    len = (right - left + 1);
                    res_start = left;
                }
                maps[s[left]]--;
                left++;//步骤2,右移左边界，使得窗口最小
            }  
        }

        return res_start == -1 ? "" : s.substr(res_start, len);
    }
};
/* 
滑动窗口的思想：
用i,j表示滑动窗口的左边界和右边界，通过改变i,j来扩展和收缩滑动窗口，可以想象成一个窗口在字符串上游走，当这个窗口包含的元素满足条件，即包含字符串T的所有元素，
记录下这个滑动窗口的长度j-i+1，这些长度中的最小值就是要求的结果。


步骤一
不断增加j使滑动窗口增大，直到窗口包含了T的所有元素

步骤二
不断增加i使滑动窗口缩小，因为是要求最小字串，所以将不必要的元素排除在外，使长度减小，直到碰到一个必须包含的元素，这个时候不能再扔了，再扔就不满足条件了，记录此时滑动窗口的长度，并保存最小值

步骤三
让i再增加一个位置，这个时候滑动窗口肯定不满足条件了，那么继续从步骤一开始执行，寻找新的满足条件的滑动窗口，如此反复，直到j超出了字符串S范围。
*/

int main(){
    Solution s1;
    cout<<s1.minWindow("ab", "b");
}