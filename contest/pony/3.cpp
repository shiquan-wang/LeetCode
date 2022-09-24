#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution{
public:
    int scch(string& str){
        stack<char> st;
        for(auto ch: str){
            st.push(ch);
        }
        vector<int> vec(4, 0);
        while (!st.empty())
        {
            /* code */
            char ch = st.top();
            st.pop();
            switch (ch)
            {
            case 'y':
                vec[0]++;
                break;
            case 'n':
                if(vec[0] > 0){
                    vec[0]--;
                    vec[1]++;
                }
                break;
            case 'o':
                if(vec[1] > 0){
                    vec[1]--;
                    vec[2]++;
                }
                break;
            case 'p':
                if(vec[2] > 0){
                    vec[2]--;
                    vec[3]++;
                }
                break;
            default:
                break;
            }
        }
        return vec[3];
        
    }
};
int main(){
    int N;
    cin>>N;
    string str;
    cin>>str;
    
    Solution s1;
    int ans = s1.scch(str);
    cout<<ans;
}