/* 
树可以看成是一个连通且 无环 的 无向 图。
给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。
图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。
请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的边。

思路：
树是一个连通且无环的无向图，在树中多了一条附加的边之后就会出现环，因此附加的边即为导致环出现的边。

可以通过并查集寻找附加的边。初始时，每个节点都属于不同的连通分量。遍历每一条边，判断这条边连接的两个顶点是否属于相同的连通分量。

    如果两个顶点属于不同的连通分量，则说明在遍历到当前的边之前，这两个顶点之间不连通，因此当前的边不会导致环出现，合并这两个顶点的连通分量。

    如果两个顶点属于相同的连通分量，则说明在遍历到当前的边之前，这两个顶点之间已经连通，因此当前的边导致环出现，为附加的边，将当前的边作为答案返回。
 */

#include<iostream>
#include<vector>
using namespace std;

class UnionFind{
private:
    vector<int> father;
    int num;
public:
    void init(int n){
        //初始化，每个节点的father节点是它本身
        father.resize(n);
        for(int i = 0; i < n; ++i){
            father[i] = i;
        }
    }

    int find(int x){
        //寻找x的祖先节点
        int root = father[x];
        while (root != father[root])//初始化后每个节点的祖先节点是它本身
        {
            /* code */
            root = father[root];
        }
        
        while (father[x] != root)//压缩路径，
        {
            /* code */
            int origin_father = father[x];
            father[x] = root;
            x = origin_father;
        }

        return root;
    }

    void merge(int a, int b){
        int root_a = find(a);
        int root_b = find(b);

        if(root_a != root_b){
            father[root_a] = root_b;
        }
    }

    bool is_connect(int a, int b){
        int root_a = find(a);
        int root_b = find(b);

        return root_a == root_b;
    }
};

class Solution{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n = edges.size();
        UnionFind uf;
        uf.init(n);

        for(auto edge : edges){
            int node1 = edge[0], node2 = edge[1];
            if(uf.is_connect(node1 - 1, node2 - 1)){//如果两个顶点属于相同的连通分量，则说明在遍历到当前的边之前，这两个顶点之间已经连通，因此当前的边导致环出现，为附加的边，将当前的边作为答案返回。
                return edge;
            }else{
                uf.merge(node1 - 1, node2 - 1);//如果两个顶点属于不同的连通分量，则说明在遍历到当前的边之前，这两个顶点之间不连通，因此当前的边不会导致环出现，合并这两个顶点的连通分量。v
            }
        }
        return {};
    }
};
