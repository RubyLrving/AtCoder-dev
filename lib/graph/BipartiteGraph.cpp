#include <bits/stdc++.h>

using namespace std;

void BipartiteGraphDfs(int v, vector<vector<int>> &graph, vector<int> &color, bool &ok){

    for(auto g:graph[v]){
        if(color[g] > -1){
            if(color[g] == color[v]){
                ok = false;
            }
            continue;
        }

        color[g] = 1 - color[v];

        BipartiteGraphDfs(g, graph, color, ok);
    }
}

void BipartiteGraphBfs(int v, vector<vector<int>> &graph, vector<int> &color, bool &ok){

    queue<int> que;
    que.push(v);

    while(que.size()){

        int p = que.front();
        que.pop();

        for(auto g:graph[p]){
            if(color[g] > -1){
                if(color[g] == color[p]){
                    ok = false;
                }
                continue;
            }

            color[g] = 1 - color[p];

            que.push(g);
        }
    }
}