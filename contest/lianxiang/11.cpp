#include<iostream>
#include<string>

using namespace std;

class Solution{
public:
    void get_ans(string& str, int m){
        int count_a = 0, count_b = 0;
        int left = 0, right = str.size() - 1;
        string ans = "";
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == 'A'){
                count_a++;
            }else{
                count_b++;
            }
        }
        if(count_b >= m){
            count_a += m;
            count_b -= m;
        }else{
            count_a += count_b;
            count_b = 0;
        }
        for(int i = 0; i < count_a; ++i){
            ans += "A";
        }
        for(int j = 0; j < count_b; ++j){
            ans += "B";
        }
        cout<<ans;
    }
};
int main(){
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    Solution s1;
    s1.get_ans(s, m);
}