#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void get_ans(vector<int> n, vector<int> m, int t){
        int ans = 0;
        int left = 0, right = 0;
        while (left < n.size() && right < m.size() && t >= 0)
        {
            /* code */
            if(n[left] <= m[right]){
                left++;
                t -= n[left];
            }else{
                right++;
                t -= m[right];
            }
            ans++;
        }
        while (left < n.size() && t >= 0)
        {
            /* code */
            left++;
            t -= n[left];
            ans++;
        }
        while (right < m.size() && t >= 0)
        {
            /* code */
            right++;
            t -= m[right];
            ans++;
        }
        cout<<ans-1;
    }
};
int main(){
    int n, m, t;
    cin>>n>>m>>t;
    vector<int> vec1;
    vector<int> vec2;
    int item;
    for(int i = 0; i < n; ++i){
        cin>>item;
        vec1.push_back(item);
    }
    for(int i = 0; i < m; ++i){
        cin>>item;
        vec2.push_back(item);
    }
    Solution s1;
    s1.get_ans(vec1, vec2, t);
}