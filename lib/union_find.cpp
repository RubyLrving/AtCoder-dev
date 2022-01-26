#include <bits/stdc++.h>

using namespace std;

class UnionFind{
private:
    vector<int> par_;

public:
    UnionFind(int N) : par_(N){
        for(int i=0; i<N; i++) par_[i] = i;
    }

    int root(int x){
        if(par_[x] == x) return x;
        return root(par_[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);

        if(rx == ry) return;
        par_[rx] = ry;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};