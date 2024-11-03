#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
    vector<int> par, rank, siz;

    UnionFind(){};
    UnionFind(int N): par(N,-1), rank(N, 0), siz(N, 1){}

    int root(int x){
        if(par[x]==-1) return x;
        else return par[x] = root(par[x]);
    }

    bool isSame(int x, int y){
        return root(x) == root(y);
    }

    bool unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return false;
        if(rank[rx]<rank[ry]) swap(rx, ry);
        par[ry] = rx;
        if(rank[rx]==rank[ry]) rank[rx]++;
        siz[rx] += siz[ry];
        return true;
    }

    int size(int x){
        return siz[root(x)];
    }
};

// 辺の定義
struct Edge {
    long long u;
    long long v;
    long long cost;
};

bool comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; } // 辺を直接比較するための関数

/* Kruskal :クラスカル法で minimum spanning tree を求める構造体
    入力: 辺のvector, 頂点数V
    最小全域木の重みの総和: sum
    計算量: O(|E|log|V|)
*/
struct Kruskal {
    UnionFind uft;
    long long sum;  // 最小全域木の重みの総和
    vector<Edge> edges;
    int V;
    
    Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) { init(); };

    void init() {
        sort(edges.begin(), edges.end(), comp_e); // 辺の重みでソート
        uft = UnionFind(V);
        sum = 0;
        for (auto e : edges) {
            if (!uft.isSame(e.u, e.v)) { // 閉路にならなければ加える
                uft.unite(e.u, e.v);
                sum += e.cost;
            }
        }
    };
};