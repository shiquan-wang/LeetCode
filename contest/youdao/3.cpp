#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> vec;
    int item;
    for(int i = 0; i < n; ++i){
        cin>>item;
        vec.push_back(item);
    }
    sort(vec.begin(), vec.end());
    int ans = 1;
    for(int i = vec.size() - k; i < vec.size(); ++i){
        ans = ans & vec[i];
    }
    cout<<ans;
    cout<<1&1
}