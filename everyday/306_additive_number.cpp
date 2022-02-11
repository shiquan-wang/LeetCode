#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
public:
    bool isAdditiveNumber(string num){
        int n = num.size();
        for(int secondStart = 1; secondStart < n-1; ++secondStart){
            if(num[0] == '0' && secondStart !=1){
                break;
            }
            for(int secondEnd = secondStart; secondEnd < n-1; ++secondEnd){
                if(num[secondStart] == '0' && secondStart != secondEnd){
                    break;
                }
                if(valid(secondStart, secondEnd, num)){
                    return true;
                }
            }
        }
    }

    bool valid(int secondStart, int  secondEnd, string num){
        int n = num.size();
        int firstStart = 0, firstEnd = secondEnd - 1;
        while(secondEnd <= n-1){
            string third = stringAdd(num,)
        }
    }
};