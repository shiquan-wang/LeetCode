#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    unordered_map<int, int> up;
    int temp;
    vector<int> vec;
    for(int i = 0; i < n; ++i){
        cin>>temp;
        vec.push_back(temp);
        if(up.count(temp) == 0){
            up[temp] = 1;
        }else{
            up[temp] ++;
        }
    }
    
    int ans = 0;
    for(int item : vec){
        if(up.count(item + k) == 1){
            ans += up[item + k];
        }
    }
    cout<<ans;
}