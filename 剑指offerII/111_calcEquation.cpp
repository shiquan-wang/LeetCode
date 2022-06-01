/* 
给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。

另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。

返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。\

思路一：广度优先遍历
我们可以将整个问题建模成一张图：给定图中的一些点（变量），以及某些边的权值（两个变量的比值），试对任意两点（两个变量）求出其路径长（两个变量的比值）。
因此，我们首先需要遍历 equations 数组，找出其中所有不同的字符串，并通过哈希表将每个不同的字符串映射成整数。
在构建完图之后，对于任何一个查询，就可以从起点出发，通过广度优先搜索的方式，不断更新起点与当前点之间的路径长度，直到搜索到终点为止。
 */
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        unordered_map<string, int> variables;
        int nvars = 0;

        int n = equations.size();
        for(int i = 0; i < n; ++i){//将所有的字符用数字表示，做出数字和字符的映射
            if(variables.count(equations[i][0]) != 1){//除法式子的一个元素被除数还没有存储到map中
                variables[equations[i][0]] = nvars++;
            }
            if(variables.count(equations[i][1]) != 1){//除数还没有存储到map中
                variables[equations[i][1]] = nvars++;
            }
        }

        //对于每个点，存储其直接连接到的所有点以及对应的权值
        vector<vector<pair<int, double>>> edges(nvars);
        for(int i = 0; i < n; ++i){
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            edges[va].push_back({vb, values[i]});
            edges[vb].push_back({va, 1.0/values[i]});
        }

        vector<double> ret;//存放每一个除法式子的结果
        for(const auto& q : queries){
            double result = -1.0;
            if(variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end()){//要查询的除法式子，被除数和除数存在于构建的图中
                int ia = variables[q[0]], ib = variables[q[1]];
                if(ia == ib){
                    result = 1;
                }else{
                    queue<int> points;
                    points.push(ia);
                    vector<double> ratios(nvars, -1.0);
                    ratios[ia] = 1.0;

                    while (!points.empty() && ratios[ib] < 0)
                    {
                        int x = points.front();
                        points.pop();

                        for(const auto [y, val] : edges[x]){
                            if(ratios[y] < 0){
                                ratios[y] = ratios[x] * val;
                                points.push(y);
                            }
                        }
                    }
                    result = ratios[ib];
                }
                
            }
            ret.push_back(result);
        }
        return ret;
    }
};