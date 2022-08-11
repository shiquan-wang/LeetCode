#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

class Solution{
public:
    int max_nums(string dic, vector<string> words){
        unordered_map<char, int> up;
        for(int i = 0; i < dic.size(); ++i){
            up[dic[i]]++;
        }
        int res = 0;
        for(int i = 0; i < words.size(); ++i){
            int temp_ans = INT_MAX;
            unordered_map<char, int> up_word;
            string word = words[i];
            for(int j = 0; j < word.size(); ++j){
                up_word[word[j]]++;
            }
            for(auto item : up_word){
                char a = item.first;
                int num = item.second;
                if(up.count(a) != 0){
                    temp_ans = min(temp_ans, up[a]/num);
                }else{
                    temp_ans = 0;
                }
            }
            res = max(res, temp_ans);
        }
        return res;
    }
};

vector<string> split(string str){
    vector<string> vec;
    int pos = 0;
    int i = 0;
    for(; i < str.size(); ++i){
        if(str[i] == ' '){
            vec.push_back(str.substr(pos, i - pos + 1));
            pos = i + 1;
        }
    }
    vec.push_back(str.substr(pos, i - pos + 1));
    return vec;
}

int main(){
    int M;
    cin>>M;
    string dic;
    // vector<string> words;
    int N;
    string str1;
    Solution s1;
    vector<int> ans;
    while (M--)
    {
        /* code */
        cin>>dic;
        cin>>N;
        // words.resize(N);
        // cin>>str1;
        // words = split(str1);
        vector<string> words;
        for(int i = 0; i < N; ++i){
            cin>>str1;
            words.push_back(str1);
        }
        ans.push_back(s1.max_nums(dic, words));
    }

    for(int i = 0; i < ans.size(); ++i){
        cout<<ans[i]<<endl;
    }
    
}