#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution{
public:
    bool checkInclusion(string s1, string s2){
        int n = s1.length(), m = s2.length();
        if(n > m) return false;
        unordered_map<char, int> map1, map2;

        for(int i = 0; i < n; ++i){
            map1[s1[i]]++;
            map2[s2[i]]++;
        }

        /* cout<<"map1"<<endl;
        for(auto iter = map1.begin(); iter != map1.end(); ++iter){
            cout<<iter->first<<" "<<iter->second<<endl;
        }

        cout<<"map2"<<endl;
        unordered_map<char, int> :: iterator iter = map2.begin();
        for(; iter != map2.end(); ++iter){
            cout<<iter->first<<" "<<iter->second<<endl;
        } */

        bool res = true;//标志位记录map1与map2是否相同
        for(auto iter = map1.begin(); iter != map1.end(); ++iter){
            if(map2[iter->first] != iter->second){
                res = false;
                break;
            }
        }

        if(res == true) return true;

        for(int i = n; i < m; ++i){
            ++map2[s2[i]];
            --map2[s2[i-n]];
            /* if(map1 == map2) 
                return true; */
            res = true;//每次比较前重置标志位
            for(auto iter = map1.begin(); iter != map1.end(); ++iter){
                if(map2[iter->first] != iter->second){
                    res = false;
                    break;
                }
            }
            if(res == true) return true;
            /* cout<<"map1"<<endl;
            for(auto iter = map1.begin(); iter != map1.end(); ++iter){
                cout<<iter->first<<" "<<iter->second<<endl;
            }

            cout<<"map2"<<endl;
            unordered_map<char, int> :: iterator iter = map2.begin();
            for(; iter != map2.end(); ++iter){
                cout<<iter->first<<" "<<iter->second<<endl;
            } */
        }

        return false;
    }
};

int main(){
    Solution s1;
    cout<<s1.checkInclusion("ab", "dboa");
    //unordered_map<char, int> map3, map4;
    /* map3['a'] = 1;
    map4['b'] = 2;
    map3['b'] = 2;
    map4['a'] = 1; 
    if(map3 == map4){
        cout<<1;
    }else {
        cout<<0;
    } */
}