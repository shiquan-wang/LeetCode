#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution{
public:
    void get_ans(float a, float b){
        float ans = 0.0;
        float temp1 = a*2*2 + b;
        float temp2 = a*2 + b*2;
        float temp3 = b*2*2 + a;
        ans = temp1*0.25 + temp2*0.5 + temp3*0.25;
        printf("%.2f", ans);
    }
};
int main(){
    float a, b;
    cin>>a>>b;
    Solution s1;
    s1.get_ans(a, b);
}