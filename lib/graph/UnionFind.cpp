#include <bits/stdc++.h> 

using namespace std;

struct UnionFind{
    vector<int> par, rank, siz;

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
