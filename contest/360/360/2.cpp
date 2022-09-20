#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    void ming_quicksort(vector<int>& vec, vector<int>& ps){
        vector<int> ans;
        vector<int> temp;
        for(int i = 0; i < ps.size(); ++i){
            ans.clear();
            temp.clear();
            int p = ps[i];
            for(int j = 0; j < vec.size(); ++j){
                if(vec[j] < p){
                    ans.push_back(vec[j]);
                }else if(vec[j] > p){
                    temp.push_back(vec[j]);
                }
            }
            ans.push_back(p);
            // for(int k = 0; k < vec.size(); ++k){
            //     if(vec[k] > p){
            //         ans.push_back(vec[k]);
            //     }
            // }
            ans.insert(ans.end(), temp.begin(), temp.end());
            vec = ans;
        }
        for(auto item : ans){
            cout<<item<<" ";
        }
    }
};
int main(){
    int N;
    vector<int> vec;
    cin>>N;
    int item;
    for(int i = 0; i < N; ++i){
        cin>>item;
        vec.push_back(item);
    }
    int n;
    vector<int> ps;
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>item;
        ps.push_back(item);
    }
    Solution s;
    s.ming_quicksort(vec, ps);
}