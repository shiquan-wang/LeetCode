#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
    void changcheng(vector<int>& vec){
        int count_ji = 0, count_ou = 0;//奇数位和偶数位出现次数最多的数的次数
        int ji, ou;//奇数位和偶数位出现次数最多的数
        int ji_2, ou_2;//奇数位和偶数位出现次数第二多的数
        int count_1 = 0, count_2 = 0;//奇数和偶数的总个数
        int ans = 100000;
        unordered_map<int, int> up1;
        unordered_map<int, int> up2;
        for(int i = 0; i < vec.size(); ++i){
            if(i % 2 == 1){
                if(up1.count(vec[i] == 0)){
                    up1[vec[i]] = 1;
                }else{
                    up1[vec[i]]++;
                }
                if(count_ji < up1[vec[i]]){
                    ji_2 = ji;
                    count_ji = up1[vec[i]];
                    ji = vec[i];
                }
                count_1++;
            }else{
                if(up2.count(vec[i] == 0)){
                    up2[vec[i]] = 1;
                }else{
                    up2[vec[i]]++;
                }
                if(count_ou < up2[vec[i]]){
                    ou_2 = ou;
                    count_ou = up2[vec[i]];
                    ou = vec[i];
                }
                // count_ou = max(count_ou, up2[vec[i]]);
                count_2++;
            }
        }
        // if(ji != ou){
        //     ans = min(ans, (count_1 - count_ji) + (count_2 - count_ou));
        // }else{
        //     ans = min(ans, (count_1 - up1[ji_2]) + (count_2 - count_ou));
        //     ans = min(ans, (count_1 - count_ji) + (count_2 - up2[ou_2]));
        // }
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