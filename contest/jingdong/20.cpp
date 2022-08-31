#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
    void changcheng(vector<int>& vec){
        int count_ji = 0, count_ou = 0;
        int count_1 = 0, count_2 = 0;
        int ans = 0;
        unordered_map<int, int> up1;
        unordered_map<int, int> up2;
        for(int i = 0; i < vec.size(); ++i){
            if(i % 2 == 1){
                if(up1.count(vec[i]) == 0){
                    up1[vec[i]] = 1;
                }else{
                    up1[vec[i]]++;
                }
                count_ji = max(count_ji, up1[vec[i]]);
                count_1++;
            }else{
                if(up2.count(vec[i]) == 0){
                    up2[vec[i]] = 1;
                }else{
                    up2[vec[i]]++;
                }
                count_ou = max(count_ou, up2[vec[i]]);
                count_2++;
            }
        }
        ans = (count_1 - count_ji) + (count_2 - count_ou);
        cout<<ans;

    }
};
int main(){
    int n;
    vector<int> vec;
    int item;
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>item;
        vec.push_back(item);
    }
    Solution s1;
    s1.changcheng(vec);
}