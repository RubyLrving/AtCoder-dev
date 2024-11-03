#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e18;    // 初期化で使う十分大きな数

// 辺情報を表す構造体
struct edge {
    long long to;     // 辺の終点
    long long leng;   // 辺の重み
};

vector<long long> dijkstra(vector<vector<edge>>& G, int N){

    vector<long long> dist(N, INF);        // dist[i]：頂点 0 から頂点 i への暫定的な経路長
    vector<bool> done(N, false);    // done[i]：頂点 i の最短距離が確定しているか
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> que;
    que.push(make_pair(0, 0));
    dist[0] = 0;

    while(que.size()) {
        long long d = que.top().first;
        long long i = que.top().second;
        que.pop();

        if (done[i]) continue;
        done[i] = true;

        for(auto e : G[i]) {
            if(dist[e.to] > dist[i] + e.leng){
                dist[e.to] = dist[i] + e.leng;
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    return dist;
}