#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int gcb(int a, int b){
        int c = 0;
        while (c = a % b)
        {
            a = b;
            b = c;
        }
        return b;
    }
    int get_min(int a, int b, int c){
        // int temp1 = a*b;
        int ans1 = (a * b) / gcb(a, b);
        int ans = (ans1 * c) / gcb(ans1, c);
        return ans;
    }
};

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    Solution s1;
    cout<<s1.get_min(a, b, c);
}