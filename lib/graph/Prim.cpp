#include <bits/stdc++.h>

using namespace std;

long long Prim(int N, vector<vector<long long>> &cost){

    long long INF = 2e18;
    vector<long long> mincost(N, INF);
    vector<bool> used(N, false);

    mincost[0] = 0;
    long long res = 0;

    while(true){
        int v = -1;
        for(int i=0; i < N; i++){
            if(!used[i] && (v == -1 || mincost[i] < mincost[v])) v = i;
        }

        if(v == -1) break;

        used[v] = true;
        res += mincost[v];

        for(int i=0; i<N; i++){
            mincost[i] = min(mincost[i], cost[v][i]);
        }
    }
    
    return res;
}