#include<iostream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct node
{
    int start;
    int end;
};
bool cmp(node a, node b){
    if(a.start != b.start){
        return a.start < b.start;
    }else{
        return a.end < b.end;
    }
}
class Solution{
public:
    void get_count_time(vector<node>& nodes){
        int n = nodes.size();
        unordered_map<int, vector<int>> up;
        int max_count = 0;
        for(int i = nodes[0].start; i <= nodes[n-1].end; ++i){
            int count = 0;
            for(int j = 0; j < n; ++j){
                if(nodes[j].start <= i && nodes[j].end >= i){
                    count++;
                }else if(nodes[j].start > i){
                    break;
                }
            }
            up[count].push_back(i);
            max_count = max(max_count, count);
        }
        cout<<max_count<<" "<<up[max_count].size();

    }
};
int main(){
    int n;
    cin>>n;
    vector<node> nodes(n);
    int temp;
    for(int i = 0; i < n; ++i){
        cin>>temp;
        nodes[i].start = temp;
    }
    for(int i = 0; i < n; ++i){
        cin>>temp;
        nodes[i].end = temp;
    }
    sort(nodes.begin(), nodes.end(), cmp);
    // for(auto node: nodes){
    //     cout<<node.start<<node.end<<endl;
    // }
    Solution s1;
    s1.get_count_time(nodes);
}