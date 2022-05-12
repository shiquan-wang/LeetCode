#include<iostream>
#include<vector>
#include<string>

using namespace std;
/* 
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
思路一: 所有的解使用回溯法，类似于086分割所有回文子字符串，是一个组合问题， 
区别在于使用pointnum来记录添加','的数量，当pointnum等于3的时候，说明字符串s已经被切割成了4段，

tips：atoi 参数是const char* 因此与需要使用c_str()函数将string转换为const char *
string str = "879"
int val = atoi(str.c_str());
stoi 参数是const string *,不需要使用c_str()进行转换
int val2 = stoi(str)
 */
class Solution{
private:
    vector<string> res;
    string path;
public:
    bool is_rule(const string& s, int start, int end){//判断start-end之间的字符串s是否符合ip地址要求
        if(end - start > 2) return false;//ip地址不能超过255,所以start和end之间最多三位
        if(end != start && s[start] == '0') return false;//ip地址的先导不能是0,当ip大于一位数字时首位不能是0
        int ip = stoi(s.substr(start, end - start + 1));//将ip地址由字符串转换为数字进行范围校验
        if(ip < 0 || ip > 255){
            return false;
        }
        return true;
    }
    void backtracking(const string& s, int start_index){
        if(start_index >= s.size()){
            path.pop_back();//去除最后的'.'
            res.push_back(path);
            return;
        }

        for(int i = start_index; i < s.size(); ++i){
            
            if(is_rule(s, start_index, i)){
                int len = i - start_index + 1;
                // path.push_back(s.substr(start_index, i - start_index + 1));
                path.append(s.substr(start_index, i - start_index + 1));
                path.push_back('.');
                backtracking(s, i+1);
                path.pop_back();
                while (len > 0)
                {
                    path.pop_back();
                    len--;
                }
            }else{
                // continue;
                break;
            }
            // backtracking(s, i+1);
            // path.pop_back();
            // while (len > 0)
            // {
            //     path.pop_back();
            // }
        }
    }
    vector<string> restoreIpAddresses(string s){
        res.clear();
        path.clear();
        backtracking(s, 0);
        return res;
    }
};

class Solution1{
private:
    vector<string> res;
    string path;
public:
    bool is_vaild(const string& s, int start, int end){
        if(start > end) return false;

        if(end - start > 2) return false;//ip地址不能超过255,所以start和end之间最多三位

        if(end != start && s[start] == '0') return false;//ip地址的先导不能是0,当ip大于一位数字时首位不能是0

        int ip = stoi(s.substr(start, end - start + 1));//将ip地址由字符串转换为数字进行范围校验

        if(ip < 0 || ip > 255){
            return false;
        }
        return true;
    }
    void backtracking(string& s, int start_index, int point_num){//start_index, 下一段ip地址的起始位置，point_num添加的逗号数量
        if(point_num == 3){
            if(is_vaild(s, start_index, s.size() - 1)){
                res.push_back(s);
            }
        }

        for(int i = start_index; i < s.size(); ++i){
            if(is_vaild(s, start_index, i)){
                s.insert(s.begin() + i + 1, '.');
                point_num++;
                backtracking(s, i+2, point_num);
                point_num--;
                s.erase(s.begin() + i + 1);
            }else{
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s){
        res.clear();
        if(s.size() > 12) return res;
        backtracking(s, 0, 0);
        return res;
    }
};

int main(){
    string s = "1111";
    Solution s1;
    vector<string> res = s1.restoreIpAddresses(s);
}