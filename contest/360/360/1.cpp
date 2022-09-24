#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
public:
    bool is_use(string str){
        if(str.size() > 10) return false;
        bool flag = true;
        for(auto item: str){
            if(!isalpha(item)){
                flag = false;
                break;
            }
        }
        return flag;
    }
};
int main(){
    string str;
    int N;
    Solution s1;
    int ans = 0;
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>str;
        bool flag = s1.is_use(str);
        if(flag == true){
            ans++;
        }
    }
    cout<<ans;
}