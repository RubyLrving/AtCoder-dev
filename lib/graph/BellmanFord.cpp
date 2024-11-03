#include <bits/stdc++.h>

using namespace std;

struct Eage {
    int from;
    int to;
    int cost;
};

int INF = 1e9;

void ShortsetPath(int s, int v, vector<Eage> &graph, vector<int> &d){
    d[s] = 0;

    while(true){
        bool update = false;

        for(int i=0; i<graph.size(); i++){
            Eage e = graph[i];
            if(d[e.to] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }

        if(!update) break;
    }
}