#include<iostream>
#include<string>

using namespace std;

class Solution{
public:
    void get_ans(string& str, int m){
        int count = 0;
        int left = 0, right = str.size() - 1;
        while (left < right){
            while(left < right && str[left] == 'A'){
                ++left;
            }
            while(left < right && str[right] =='B'){
                --right;
            }
            if(left >= right){
                break;
            }
            if(count < m){
                swap(str[left], str[right]);
                count++;
            }else{
                break;
            }
        }
        // cout<<str<<count;
        int leave = m - count;
        if(leave < 0){
            cout<<str;
        }else{
            for(int i = 0; i < str.size(); ++i){
                if(str[i] == 'B'){
                    str[i] = 'A';
                    leave--;
                }
                if(leave <= 0){
                    break;
                }
            }
            cout<<str;
        }
        
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