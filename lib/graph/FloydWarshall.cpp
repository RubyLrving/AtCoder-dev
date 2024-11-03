#include <bits/stdc++.h>

using namespace std;

long long INF = 2e18;

struct Eage {
    int from;
    int to;
    int cost;
};

long long FloydWarshall(int N, vector<vector<long long>> &dist, vector<Eage> graph){
    
    for(int i=0; i < N; i++) for(int j=0; j < N; j++) dist[i][j] = INF;
    for(int i=0; i < N; i++) dist[i][i] = 0;

    for(auto g:graph){
        dist[g.from][g.to] = g.cost;
    }
    
    long long ans = 0;
    for(int k=0; k < N; k++){
        for(int i=0; i < N; i++){
            for(int j=0; j < N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }

        for(int i=0; i < N; i++){
            for(int j=0; j < N; j++){
                if(dist[i][j] < INF) ans += dist[i][j];
            }
        }
    }

    return ans;
}