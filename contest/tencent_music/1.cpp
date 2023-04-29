#include<iostream>
#include<string>

using namespace std;

class Solution{
public:
    int get_min_maxValue(string str){
        int res = 0, value;
        for(int i = 0; i < str.size(); ++i){
            char temp = str[i];
            for(int j = i + 1; j < str.size(); ++j){
                if(str[j] != temp){
                    value = j-i;
                    break;
                }
            }
            res += value;
        }
        return res;
    }
};

int main(){
    string str;
    int k;
    cin>>str;
    cin>>k;
    Solution s1;
    cout<<s1.get_min_maxValue(str);
}