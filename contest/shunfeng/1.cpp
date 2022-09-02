#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;
typedef long long ll;

class Solution{
public:
    bool is_yu(string& str){
        int count = 0;
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == '5'){
                count++;
            }
        }
        return count >= 5 ? true : false;
    }
    string nums_yu(string& str){
        ll n = stoi(str);
        if(n < 55555){
            return "55555";
        }
        bool flag = false;
        while (!flag)
        {
            n++;
            string str = to_string(n);
            flag = is_yu(str);
        }
        return to_string(n);
    }
};
int main(){
    string str;
    cin>>str;
    Solution s1;
    cout<<s1.nums_yu(str);
}