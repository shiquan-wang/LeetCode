#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp_s, temp_t;
        int ls = 0, lt = 0;
        /* 
        string 中的函数
        没有元素时不能使用下标来进行赋值；不能使用 = 
        push_back() 尾部添加一个元素
        append 添加一个字符串
        pop_back() 尾部删除一个元素
        erase(char) || erase(char, len)
         */
        for(int i  = 0; i < s.length(); ++i){
            if(s[i] != '#'){
                temp_s.push_back(s[i]);
            }else if(!temp_s.empty()){
                temp_s.pop_back();
            }
        }
        cout<<temp_s<<endl;
        for(int i  = 0; i < t.length(); ++i){
            if(t[i] != '#'){
                temp_t.push_back(t[i]);
            }else if(!temp_t.empty()){
                temp_t.pop_back();
            }
        }
        cout<<temp_t<<endl;
        if(temp_s == temp_t){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    int n;
    string s, t;
    Solution s1;
    cout<<s1.backspaceCompare("ab#c", "ad#c");
    /* cin>>n;
    while (n > 0)
    {
        cin>>s>>t;
        cout<<s1.backspaceCompare(s, t);
        n--;
    } */
    
}