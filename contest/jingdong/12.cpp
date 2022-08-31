#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void martix(int n){
        vector<vector<int>> ans(n, vector<int>(n));
        int u = 0, d = n-1;
        int l = 0, r = n-1;
        int temp = 1;
        while (true)
        {
            /* code */
            for(int i = l; i <= r; ++i){
                ans[u][i] = temp;
                temp++;
            }
            if(++u > d) break;
            for(int i = u; i <= d; ++i){
                ans[i][r] = temp;
                temp++;
            }
            if(--r < l) break;
            for(int i = r; i >= l; --i){
                ans[d][i] = temp;
                temp++;
            }
            if(--d < u) break;
            for(int i = d; i >= u; --i){
                ans[i][l] = temp;
                temp++;
            }
            if(++l > r) break;;
        }
        for(auto vec: ans){
            for(auto item: vec){
                cout<<item<<" ";
            }
            cout<<endl;
        }
        
    }
};
int main(){
    int n;
    cin>>n;
    Solution s;
    s.martix(n);
}